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

    ll cnt = 0;
    for(auto x : a) cnt += (x == 0);

    if(cnt < 2) {
        cout << -1 << endl;
        return;
    }

    ll ct = 0;
    ct += (a[0] == 0);
    ct += (a[n - 1] == 0);
    cout << 2 - ct << endl;
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