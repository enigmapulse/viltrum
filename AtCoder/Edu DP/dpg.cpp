#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[v].push_back(u); // reverse the edge
    }
    
    vector<ll> dp(n + 1, 0);
    function<ll(ll)> f = [&] (ll v) {
        if(dp[v] != 0) return dp[v];
        for(auto child : adj[v]) dp[v] = max(dp[v], f(child) + 1);
        return dp[v];
    };

    ll best = 0;
    for (ll i = 1; i <= n; i++) {
        best = max(best, f(i));
    }
    cout << best << endl;
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