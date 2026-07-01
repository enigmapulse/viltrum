#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

const ll MAXN = 1000005;
ll spf[MAXN];

void sieve() {
    spf[1] = 1LL;
    for (ll i = 2; i < MAXN; i++) spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<ll> factor(ll n) {
    vector<ll> ret;
    while (n != 1) {
        ll val = spf[n];
        ret.push_back(val);
        while(n % val == 0) n /= val;
    }
    return ret;
}

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> cnt(m + 1, 0);
    for (ll i = m; i >= 1; i--) {
        cnt[i] = power(m / i, n - 2);
        for (ll j = 2 * i; j <= m; j+=i) {
            cnt[i] = (cnt[i] - cnt[j] + MOD) % MOD;
        }
    }
    
    ll ans = 0;
    for (ll i = 2; i <= m; i++) {
        auto primes = factor(i);
        ll ways = 0, sz = primes.size(), pairs = 0;
        for (ll mask = 1; mask < (1ll << sz); mask++) {
            ll parity = __builtin_popcountll(mask), val = 1, tot = 0;
            for (ll bit = 0; bit < sz; bit++) {
                if((mask >> bit) & 1) val = val * primes[bit];
            }
            if(parity & 1) {
                ways = (ways + (m / val) * (m / val)) % MOD;
                pairs = (pairs + (m / val)) % MOD;
            }
            else {
                ways = (ways - (m / val) * (m / val) + MOD) % MOD;
                pairs = (pairs - (m / val) + MOD) % MOD;
            }
        }
        pairs = pairs * pairs;
        ans = (ans + ((pairs - ways + MOD) % MOD) * cnt[i]) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; sieve();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}