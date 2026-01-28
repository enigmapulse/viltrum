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

    ll adj[n + 1][n + 1];
    for (ll i = 0; i < n + 1; i++) {
        for (ll j = 0; j < n + 1; j++) {
            adj[i][j] = 1e12;
        }
    }
    vector<pair<pair<ll, ll>, ll>> edges;
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
  
    ll dist[n + 1][n + 1];
    for (ll i = 0; i < n + 1; i++) {
        for (ll j = 0; j < n + 1; j++) {
            dist[i][j] = 1e12;
        }
    }
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            dist[i][j] = adj[i][j];
        }
        dist[i][i] = 0;
    }

    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    for(auto e : edges) {
        ll u = e.first.first;
        ll v = e.first.second;

        ll ans = 1e12;
        for (ll k = 1; k <= n; k++) {
            if (k == u || k == v) continue;
            if (dist[u][k] < 1e12 && dist[k][v] < 1e12)
                ans = min(ans, dist[u][k] + dist[k][v]);
        }
        if (ans == 1e12) cout << -1 << endl;
        else cout << ans << endl;
    }
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
