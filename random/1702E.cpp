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
    vector<ll> deg(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    bool flag = (*max_element(all(deg)) <= 2);
    vector<bool> vis(n + 1, false);
    vector<ll> col(n + 1, 0);
    function<void(ll, ll)> dfs = [&] (ll v, ll c) {
        if(!flag) return;
        vis[v] = true; col[v] = c;
        for(auto child : adj[v]) {
            if(!vis[child]) dfs(child, c^1);
            else if(col[child] == col[v]) {flag &= false; return;}
        }
    };

    for (ll i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
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