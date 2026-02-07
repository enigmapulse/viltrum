#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> path; path.push_back(1);
    function <void(ll, ll)> dfs = [&] (ll v, ll p) {
        if(v == n) return;
        for(auto child : adj[v]) {
            if(child == p) continue;
            path.push_back(child);
            dfs(child, v); 
            if(child == n) return;
        }
        if(path.back() == n) return;
        path.pop_back();
    };
    dfs(1, -1);

    vector<ll> sm(n + 1, 1);
    function <void(ll, ll)> calc = [&] (ll v, ll p) {
        ll sum = sm[v];
        for(auto child : adj[v]) {
            if(child == p) continue;
            calc(child, v); 
            sum += sm[child];
        }
        sm[v] = sum;
    };
    calc(1, -1);

    vector<ll> dp(path.size());
    for (ll i = 0; i < path.size() - 1; i++) {
        ll u = path[i], v = path[i + 1];
        sm[u] -= sm[v];
        dp[i] = sm[u];
        dp[i] %= MOD;
    }
    
    for (ll i = 1; i < dp.size(); i++) {
        dp[i] = (dp[i] * dp[i - 1]) % MOD;
        dp[i] = (dp[i] + (i > 1 ? dp[i - 2] : 1)) % MOD;
    }
    
    cout << dp[dp.size() - 2] << endl;
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