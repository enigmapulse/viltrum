#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;


void solve() {
    ll n, p; cin >> n >> p;
    const ll MOD = p;
    
    vector<ll> F(n + 5, 1);
    F[2] = 2;
    for (ll idx = 3; idx <= n; idx++) {
        F[idx] = (F[idx - 1] + F[idx - 2]) % MOD;
    }

    auto binpow = [&] (ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    };

    const ll inv2 = binpow(2, MOD - 2);
    auto half = [&] (ll num) {
        return (num * inv2) % MOD;
    };
    
    vector<ll> ans(n + 1, 1);
    ll sm = 1, conv = 1;
    for (ll node = 2; node <= n; node++) {
        ll pos = (sm * (F[node] % MOD)) % MOD;
        ll neg = conv;
        ll val = (pos - neg + MOD) % MOD;
        ans[node] = half(val);
        sm = (sm + ans[node]) % MOD;
        conv = (conv + (ans[node] * F[node]) % MOD) % MOD;
    }
    cout << ans[n] << endl;
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

