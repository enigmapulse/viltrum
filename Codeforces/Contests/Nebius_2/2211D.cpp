#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
#define pll pair<ll, ll>

using namespace std;

ll fact[MAXN], invFact[MAXN];

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void init_nCr() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    invFact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> ans; ans.push_back(a[n - 1]);
    vector<pll> vals; ll cur = a[n - 1];
    if(a[n - 1] != 0) vals.push_back({n, a[n - 1]});
    for (ll i = n - 2; i >= 0; i--) {
        ll curr = a[i];
        for(auto [idx, val] : vals) {
            ll sub = (nCr(idx, i + 1) * val) % MOD;
            curr = (curr - sub + MOD) % MOD;
        }
        if(curr != 0) {
            vals.push_back({i + 1, curr % MOD});
            cur |= curr;
        }
        ans.push_back(cur);
    }
    
    for(auto y : ans) cout << y << " ";
    cout << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    init_nCr();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}