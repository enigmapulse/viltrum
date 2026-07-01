#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k, s, d; cin >> n >> m >> k >> s >> d;
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<vector<ll>> dist(n + 1, vector<ll> (k + 1, INF));
    
    auto dijk = [&] (ll k) {
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({0, s});
        while(!pq.empty()) {
            auto [d, v] = pq.top(); pq.pop();
            if(d > dist[v][k]) continue;
            dist[v][k] = d;
            for(auto [ch, w] : adj[v]) {
                ll choice1 = dist[v][k] + w;
                ll choice2 = (k > 0 ? dist[v][k - 1] : INF);
                ll best = min(choice1, choice2);
                if(dist[ch][k] > best) {
                    dist[ch][k] = best;
                    pq.push({best, ch});
                }
            }
        }
    };

    ll mn = INF;
    for (ll i = 0; i <= k; i++) {
        dijk(i);
        mn = min(dist[d][i], mn);
    }
    if(mn == INF) cout << -1 << endl;
    else cout << mn << endl;
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