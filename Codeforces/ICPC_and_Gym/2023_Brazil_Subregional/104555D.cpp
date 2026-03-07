#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second
#define INF 1e15

using namespace std;

bool multipleTests = false;

void solve() {
    struct edge {
        ll st, to, len;
    };
    vector<edge> edges;

    ll n, m; cin >> n >> m;
    vector<vector<ll>> dist(n + 1, vector<ll> (n + 1, INF));
    vector<vector<ll>> adj(n + 1, vector<ll> (n + 1, INF));
    for (ll i = 0; i < m; i++) {
        ll u, v, l; cin >> u >> v >> l;
        edges.push_back({u, v, l});
        dist[u][v] = l; dist[v][u] = l;
        adj[u][v] = l; adj[v][u] = l;
    }
    
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
    
    for(auto [u, v, l] : edges) {
        ll mn = INF;
        for (ll k = 1; k <= n; k++) {
            if(dist[u][k] == l + dist[v][k]) continue;
            if(dist[k][v] == l + dist[k][u]) continue;
            mn = min(mn, dist[u][k] + dist[k][v]);
        }
        if(mn == INF) cout << -1 << endl;
        else cout << mn << endl;
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