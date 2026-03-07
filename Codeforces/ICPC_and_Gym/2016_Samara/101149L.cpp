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
    ll n, m, a, b; cin >> n >> m >> a >> b;
    vector<vector<ll>> adj1(n + 1), adj2(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    auto bfs = [&] (ll s, vector<ll>& dist, vector<vector<ll>>& ad) {
        queue<ll> q; q.push(s); dist[s] = 0;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(auto ch : ad[u]) {
                if(dist[ch] == INF) {
                    dist[ch] = dist[u] + 1;
                    q.push(ch);
                }
            }
        }
    };

    ll mn = INF;
    vector<ll> f(n + 1, INF), g(n + 1, INF), h(n + 1, INF);
    bfs(0, f, adj1); bfs(a, g, adj2); bfs(b, h, adj2); 
    for(ll i = 1; i <= n; ++i) {
        mn = min({mn, f[i] + g[i] + h[i]});
    }

    cout << mn << endl;
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