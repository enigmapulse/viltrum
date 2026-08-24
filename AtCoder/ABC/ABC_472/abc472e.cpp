#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll last = -1, first = -1;
    vector<ll> par(n + 1), dist(n + 1, -1);
    auto dfs = [&] (auto&& dfs, ll v) -> void {
        if (last != -1) return;
        for(auto ch : adj[v]) {
            if(ch == par[v]) continue;
            if(dist[ch] == -1) {
                dist[ch] = dist[v] + 1;
                par[ch] = v;
                dfs(dfs, ch);
                if (last != -1) return; 
            }
            else if (dist[ch] < dist[v]) { 
                if((dist[v] - dist[ch]) % 2 == 0) {
                    last = v;
                    first = ch;
                    return;
                }
            }
        }
    };
    par[1] = 1; dist[1] = 0;
    dfs(dfs, 1);

    if(last == -1) cout << -1 << endl;
    else {
        vector<ll> res = {last};
        while(last != first) {
            last = par[last];
            res.push_back(last);
        } 
        cout << res.size() << endl;
        for(auto x : res) cout << x << " ";
        cout << endl;
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