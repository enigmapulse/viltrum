#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; 
    ll base = 0, extra = 0;
    for (ll i = 0; i < n; i++) {
        ll c0, c1, r0, r1; cin >> c0 >> c1 >> r0 >> r1;
        base += abs(c0 - r0) + abs(c1 - r1);
        if(r1 < c1) extra += min(c0, r0);
    }
    cout << (base / 2) + extra << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}