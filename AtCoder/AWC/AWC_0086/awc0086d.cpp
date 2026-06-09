#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e15;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<ll> dist(n + 1, INF); dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q; q.push({0, 1});
    while (!q.empty()) {
        auto [d, v] = q.top(); q.pop();
        if(dist[v] < d) continue;
        for(auto [child, weight] : adj[v]) {
            if(d + weight < dist[child]) {
                dist[child] = d + weight;
                q.push({dist[child], child});
            }
        }
    }
    if(dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
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