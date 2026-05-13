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
    vector<vector<pair<ll,ll>>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    bool chk = true;
    vector<ll> vis(n + 1, -1); vector<ll> comp;
    function<void(ll, ll)> dfs = [&](ll v, ll curr) {
        vis[v] = curr;
        comp.push_back(v);
        for (auto &[to, w] : adj[v]) {
            if (vis[to] == -1) dfs(to, curr ^ w);
            else if((curr ^ vis[to]) != w) chk = false; 
        }
    };

    for (ll i = 1; i <= n; i++) {
        if(vis[i] == -1) {
            chk = true; comp.clear();
            dfs(i, 0);
            if(!chk) {
                cout << -1 << endl;
                return;
            }
            else {
                vector<ll> vals;
                for(auto x : comp) vals.push_back(vis[x]);
                ll x = 0;
                for (int b = 0; b < 60; b++) {
                    ll cnt1 = 0;
                    for (ll i = 0; i < vals.size(); i++) if (vals[i] & (1LL << b)) cnt1++;
                    ll cnt0 = vals.size() - cnt1;
                    if (cnt1 > cnt0) {
                        x |= (1LL << b);
                    }
                }
                for(auto y : comp) vis[y] = vis[y] ^ x;
            }
        }
    }
    
    for(ll i = 1; i <= n; ++i) {
        cout << vis[i] << " ";
    }
    cout << endl;
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