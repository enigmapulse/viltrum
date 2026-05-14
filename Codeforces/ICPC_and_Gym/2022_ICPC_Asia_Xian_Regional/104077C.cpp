#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c; cin >> a >> b >> c;

    map<ll, ll> dp;
    function<ll(ll)> f = [&] (ll x) {
        if(dp.count(x)) return dp[x];
        if(x == 1) return b;
        ll clone = a + max(f(x / 2), f((x + 1)/ 2));
        return dp[x] = min(x * b, clone);
    };

    cout << f(c) << endl;
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