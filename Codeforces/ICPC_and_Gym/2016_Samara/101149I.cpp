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
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll mn = 1e12, chosen = 0;
    for (ll i = 1; i <= n; i++) {
        if(1 + adj[i].size() < mn) {
            mn = 1 + adj[i].size();
            chosen = i;
        }
    }
    
    vector<ll> ans(n + 1, 1); ans[chosen] = 0;
    for(auto child : adj[chosen]) ans[child] = 0;

    for(ll i = 1; i <= n; ++i) cout << ans[i] << " ";
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