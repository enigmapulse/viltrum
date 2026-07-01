#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll MOD = 1e9 + 7;

using namespace std;

const ll MAXN = 5 * 1e5 + 5;
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

vector<ll> getFactorization(ll n) {
    vector<ll> ret;
    while (n != 1) {
        ret.push_back(spf[n]);
        n /= spf[n];
    }
    return ret;
}

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n); inarr(a, n);
    map<ll, ll> cnt;
    for (ll i = 0; i < n; i++) {
        for(auto x : getFactorization(a[i])) cnt[x] = (cnt[x] + 1) % MOD;
    }
    
    ll ans = 1;
    for(auto [p, f] : cnt) ans = (ans * ((f + 1) % MOD) % MOD);
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