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
    vector<vector<ll>> adj(n + 1, vector<ll> (n + 1, -1));
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    vector<ll> vis(n + 1, false);
    function<ll(ll, ll)> dfs = [&] (ll v, ll curr) {
        if(v == n) return curr;
        ll mx = LLONG_MAX;
        for (ll i = 1; i <= n; i++) {
            if(adj[v][i] == -1 || vis[i]) continue;
            vis[i] = true;
            mx = min(mx, dfs(i, curr ^ adj[v][i]));
            vis[i] = false;
        }
        return mx;
    };

    vis[1] = true;
    ll ans = dfs(1, 0);
    cout << ans << endl;
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