#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> deg(n + 1, 0), col(n + 1, 0); ll chosen = -1;
    for (ll i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if(deg[i] == 2) chosen = i;
    }
    if(chosen == -1) {
        cout << "NO" << endl;
        return;
    }
    
    vector<vector<ll>> nadj(n + 1);
    function<void(ll, ll, ll)> dfs  = [&] (ll v, ll p, ll c) {
        col[v] = c;
        for(auto child : adj[v]) {
            if(child == p) continue;
            if(c == 1) nadj[child].push_back(v);
            else nadj[v].push_back(child);
            dfs(child, v, c ^ 1);
        }
    };
    nadj[chosen].push_back(adj[chosen][1]);
    nadj[adj[chosen][0]].push_back(chosen);
    dfs(adj[chosen][0], chosen, 0);
    dfs(adj[chosen][1], chosen, 1);

    cout << "YES" << endl;
    for (ll i = 1; i <= n; i++) {
        for(auto v : nadj[i]) cout << i << " " << v << endl;
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