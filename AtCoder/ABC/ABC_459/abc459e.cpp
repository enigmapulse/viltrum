#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;
bool multipleTests = false;

const ll MAXD = 1e6 + 5;
ll invFact[MAXD];

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void precompute() {
    ll curr = 1;
    for (ll i = 1; i < MAXD; i++) {
        curr = (curr * i) % MOD;
    }
    invFact[MAXD - 1] = power(curr, MOD - 2);

    for (ll i = MAXD - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(ll n, ll r) {
    n = n % MOD;
    if (r < 0 || n < r) return 0;

    ll num = 1;
    for (ll i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
    }
    return (num * invFact[r]) % MOD;
}

void solve() {
    ll n; cin >> n;
    vector<ll> p(n - 1); inarr(p, n - 1);
    vector<ll> c(n); inarr(c, n);
    vector<ll> d(n); inarr(d, n);

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        adj[p[i]].push_back(i + 2);
    }

    ll ways = 1;
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        ll curr = c[v - 1];
        for(auto child : adj[v]) {
            dfs(child, v);
            curr += c[child - 1];
        }
        
        if (curr < d[v - 1]) {
            ways = 0;
            c[v - 1] = 0; 
            return;
        }

        ways = (ways * nCr(curr, d[v - 1])) % MOD;
        c[v - 1] = curr - d[v - 1];
    };
    dfs(1, -1);
    
    cout << ways << endl;
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