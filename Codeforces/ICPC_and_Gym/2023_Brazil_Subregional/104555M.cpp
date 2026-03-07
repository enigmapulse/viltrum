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

ll dijkstra (ll n, ll u, ll v, const vector<vector<ll>>& adj) {
    vector<ll> d(n + 1, INF); d[u] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, u});

    while (!pq.empty()) {
        auto [dist, node] = pq.top(); pq.pop();
        if(node == v) return dist;
        if(d[node] < dist) continue;

        for (ll neigh = 1; neigh <= n; neigh++) {
            if(adj[node][neigh] == 0) continue;
            if (d[neigh] > dist + adj[node][neigh]) {
                d[neigh] = dist + adj[node][neigh];
                pq.push({d[neigh], neigh});
            }
        }
    }
    
    return -1;
}

void solve() {
    ll n; cin >> n;

    vector<vector<ll>> adj(n + 1, vector<ll> (n + 1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    /*
    k loop
    i loop
    j loop
    dist[i][j] = min(dist[i][j], dust[i][k] + dist[k][j]);
    */
    
    bool chk = true;
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                ll nwd = adj[i][k] + adj[k][j];
                chk &= (nwd >= adj[i][j]);
                if(!chk) break;
            }
            if(!chk) break;
        }
        if(!chk) break;
    }    
    if(!chk) {
        cout << -1 << endl;
        return;
    }

    /*
    loop i
    loop j
    I have selceted an edge now
    loop k
    check dist[i][j] == dist[i][k] + dist[k][j]
    */

    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            if(adj[i][j] == 0) continue;
            ll tmp = adj[i][j]; adj[i][j] = 0;
            ll res = dijkstra(n, i, j, adj);
            if(res == tmp) cnt++;
            else adj[i][j] = tmp;
        }
    }
    
    cout << cnt << endl;
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