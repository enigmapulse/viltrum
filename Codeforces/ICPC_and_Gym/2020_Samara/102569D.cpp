#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define INF 1e12

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, char>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; char ch;
        cin >> u >> v >> ch;
        adj[u].push_back({v, ch});
        adj[v].push_back({u, ch});
    }
    
    vector<ll> dist(n + 1, INF); dist[n] = 0;
    queue<ll> q; q.push(n);
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto [neigh, ch] : adj[u]) {
            if(dist[neigh] == INF) {
                dist[neigh] = dist[u] + 1;
                q.push(neigh);
            }
        }
    }

    vector<ll> nxt; nxt.push_back(1);
    vector<ll> par(n + 1, -1);
    string ans = "";
    while(true) {
        if(nxt.back() == n) break;
        char best = 'z';
        vector<ll> cur;
        for(auto u : nxt){
            for(auto [v, ch] : adj[u]) {
                if(dist[v] == dist[u] - 1) {
                    if(best > ch) {
                        best = ch;
                    }
                }
            }
        }

        for(auto u : nxt){
            for(auto [v, ch] : adj[u]) {
                if(dist[v] == dist[u] - 1 && ch==best) {
                    cur.push_back(v);
                    par[v] = u;
                }
            }
        }

        sort(all(cur));
        cur.erase(unique(all(cur)), cur.end());

        ans += best;
        nxt = cur;
    }

    vector<ll> path; path.push_back(n);
    while (true) {
        if(path.back() == 1) break;
        path.push_back(par[path.back()]);
    }
    reverse(all(path));

    cout << path.size() - 1 << endl;
    for(auto u : path) cout << u << " ";
    cout << endl;

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