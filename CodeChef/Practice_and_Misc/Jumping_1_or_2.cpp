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

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll mul(ll x, ll y) {
    x = x % MOD;
    y = y % MOD;
    return (x * y) % MOD;
}

ll divide(ll d, ll q) {
    d = d % MOD;
    ll I = inv(q);
    return (d * I) % MOD;
}

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> dp(max(n + 1, 4LL), 0);
    dp[1] = divide(mul(m % MOD, (m + 1) % MOD), 2);
    dp[2] = mul(2, mul(m, dp[1]));
    dp[3] = mul(m, dp[2]);

    if(n < 4) {
        cout << dp[n] << endl;
        return;
    }

    for (ll i = 4; i <= n; i++) {
        ll contr1 = mul(binpow(m, 3), dp[i - 3]);
        ll contr2 = divide(mul(binpow(m, i), (m + 1)), 2);
        ll contr3 = divide(mul(mul(binpow(m, i - 1), m + 1), 2 * m + 1), 6);
        dp[i] = ((contr1 + contr2) % MOD + contr3) % MOD;
    }
    
    cout << dp[n] << endl;
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