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
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> subtree(n, 0);
    auto dfs = [&] (auto&& dfs, ll v, ll p) -> void {
        subtree[v] = 1;
        for(auto ch : adj[v]) {
            if(ch == p) continue;
            dfs(dfs, ch, v);
            subtree[v] += subtree[ch];
        }
    };
    dfs(dfs, 0, -1);

    ll tot = accumulate(all(subtree), 0ll);
    cout << tot - subtree[0] << endl;

    vector<ll> ans(n, 0);
    auto reroot = [&] (auto&& reroot, ll v, ll p) -> void {
        ll oldp = subtree[p];
        ll oldv = subtree[v];
        ll old_tot = tot;

        swap(subtree[v], subtree[p]);
        tot += subtree[v] - 2 * subtree[p];
        ans[v] = tot - subtree[v];
        subtree[p] = subtree[v] - subtree[p];
        for(auto ch : adj[v]) {
            if(ch == p) continue;
            reroot(reroot, ch, v);
        }
        subtree[p] = oldp;
        subtree[v] = oldv;
        tot = old_tot;
    };
    for (auto ch : adj[0]) {
        reroot(reroot, ch, 0);
    }

    for (ll i = 1; i < n; i++) {
        cout << ans[i] << " ";
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