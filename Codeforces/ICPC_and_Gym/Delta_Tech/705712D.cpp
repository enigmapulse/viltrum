#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> mark(n + 1); inarr(mark, n);

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> res;
    vector<bool> vis(n + 1, false);
    queue<ll> q; q.push(1); vis[1] = true;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        res.push_back(u);
        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    ll cnt = 0;
    auto dfs = [&] (auto&& dfs, ll v, ll p, ll ct) -> void {
        ll curr = ct + mark[v];
        if(curr & 1) cnt += 1 - mark[v];
        else cnt += mark[v];
        for(auto ch : adj[v]) {
            if(ch == p) continue;
            dfs(dfs, ch, v, curr);
        }
    };
    dfs(dfs, 1, -1, 0);

    cout << cnt << endl;
    reverse(all(res));
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
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