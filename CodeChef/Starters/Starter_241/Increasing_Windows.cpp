#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const int MAXN = 200005;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

ll fact[MAXN], invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> cnt(k + 1, 0); cnt[1] = 1;
    ll sm = 1;
    for (ll i = 2; i <= k; i++) {
        cnt[i] = (power(i, k) - sm + MOD) % MOD;
        sm = (sm + cnt[i]) % MOD;
    }
    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        ans = (ans + (cnt[i] * nCr(n - i, n - k)) % MOD) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; precompute();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}