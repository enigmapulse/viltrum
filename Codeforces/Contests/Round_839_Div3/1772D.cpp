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
    vector<ll> a(n); inarr(a, n);
    ll left = 0, right = 1e12;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) left = max(left, a[i] + a[i + 1]);
        if(a[i] < a[i + 1]) right = min(right, a[i] + a[i + 1]);
    }
    
    if(left > right || (left == right && (left & 1))) cout << -1 << endl;
    else cout << (left + 1) / 2 << endl;
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