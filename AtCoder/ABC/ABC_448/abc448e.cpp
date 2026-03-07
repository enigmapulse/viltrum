#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;
bool multipleTests = false;

ll binpow(ll base, ll exp, ll MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % MOD;
        base = (__int128)base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll k, m; cin >> k >> m;

    ll MOD = 10007LL * m;
    ll curr = 0;

    for (ll i = 0; i < k; i++) {
        ll x, y; cin >> x >> y;
        ll p = binpow(10, y, MOD);
        curr = (__int128)curr * p % MOD;
        ll val = binpow(10, y, 9 * MOD) - 1;
        val = (val + 9 * MOD) % (9 * MOD);
        val /= 9;
        curr = (curr + (__int128)x * val) % MOD;
    }

    cout << (curr / m) % 10007 << endl;
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