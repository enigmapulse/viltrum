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

ll modinv(ll n) {
    return binpow(n, MOD - 2);
}

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> dp(m + 1, 0); dp[0] = 1;

    struct r {
        ll l, weight;
    };

    ll K = 1;
    // we wanna store all the segm ending at one point at same place
    vector<vector<r>> end(m + 1);
    for (ll i = 0; i < n; i++) {
        ll l, r, p, q; cin >> l >> r >> p >> q;
        K = (K * ((q - p)*modinv(q) % MOD)) % MOD;
        ll w = (p * modinv(q - p)) % MOD;
        end[r].push_back({l, w});
    }
    
    for (ll i = 0; i <= m; i++) {
        if(end[i].empty()) continue;
        for(auto prev : end[i]) {
            dp[i] += (dp[prev.l - 1] * prev.weight);
            dp[i] %= MOD;
        }
    }
    
    cout << (dp[m] * K) % MOD << endl;
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