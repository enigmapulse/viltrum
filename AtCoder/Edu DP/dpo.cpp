#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> adj(n, vector<ll> (n));
    for (ll i = 0; i < n; i++) inarr(adj[i], n);
    
    vector<vector<ll>> dp(n + 1, vector<ll>(1LL << n, 0)); dp[0][0] = 1;
    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll i = __builtin_popcount(mask);
        for (ll j = 0; j < n; j++) {
            if(adj[i][j] & !((mask >> j) & 1)) dp[i + 1][mask] = (dp[i + 1][mask] + dp[i][mask ^ (1 << j)]) % MOD;
        }
    }

    cout << dp[n][(1LL << n) - 1] << endl;
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