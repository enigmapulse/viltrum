#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modinv (ll n) {
    return binpow(n, MOD - 2);
}

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;

    ll dp2 = ((m * (m + 1)) % MOD) * modinv(2), dp1 = m;
    dp1 %= MOD; dp2 %= MOD;
    for (ll i = 2; i <= n; i++) {
        ll ndp1 = ((((m * (m + 1)) % MOD * modinv(2)) % MOD) * dp1) % MOD + (m * dp2) % MOD;
        ll ndp2 = (((((m * (m + 1)) % MOD * (2*m + 1)) % MOD * modinv(6)) % MOD) * dp1) % MOD + ((((m * (m + 1)) % MOD * modinv(2)) % MOD) * dp2) % MOD;
        dp1 = ndp1; dp2 = ndp2;
        dp1 %= MOD; dp2 %= MOD;
    }
    
    cout << dp1 << endl;
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