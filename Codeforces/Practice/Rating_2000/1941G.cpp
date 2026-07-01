#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define tlll tuple<ll, ll, ll>
const ll INF = 1e18;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    ll start, end; cin >> start >> end;
    
    vector<ll> dist(n + 1, INF); 
    priority_queue<tlll, vector<tlll>, greater<tlll>> pq; pq.push({0, -1, start});

    while(!pq.empty()) {
        auto [d, c, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;
        dist[v] = d;
        for(auto [child, col] : adj[v]) {
            ll ndist = 0;
            if(c == -1 || col == c) ndist = d;
            else ndist = d + 1;
            if(ndist < dist[child]) {
                dist[child] = ndist;
                pq.push({ndist, col, child});
            }
        }
    }

    cout << dist[end] << endl;
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