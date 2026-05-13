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
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll> (2, 1));
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        for(auto child : adj[v]) {
            if(child == p) continue;
            dfs(child, v);
            dp[v][0] = (dp[v][0] * (dp[child][0] + dp[child][1]) % MOD) % MOD;
            dp[v][1] = (dp[v][1] * dp[child][0]) % MOD;
        }
    };

    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
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