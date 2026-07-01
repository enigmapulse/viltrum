#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define tlll tuple<ll, ll, ll>
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> E(n + 1, -1);
    priority_queue<tlll, vector<tlll>, greater<tlll>> q; q.push({0, 0, 1});
    while(!q.empty()) {
        auto [t, w, u] = q.top(); q.pop();
        if(t - w <= E[u]) continue;
        E[u] = t - w;
        if(u == n) {
            cout << t << " " << w << endl;
            return;
        }
        for (ll i = 0; i < adj[u].size(); i++) {
            ll ntime = t + i + 1;
            ll nwait = w + i;
            ll nxt = adj[u][(t + i) % adj[u].size()];
            q.push({ntime, nwait, nxt});
        }
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