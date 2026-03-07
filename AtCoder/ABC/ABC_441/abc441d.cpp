#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, l, s, t; cin >> n >> m >> l >> s >> t;

    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, l; cin >> u >> v >> l;
        adj[u].push_back({v, l});
    }

    vector<ll> ans(n + 1, 0);

    function <void(ll, ll, ll)> dfs = [&] (ll v, ll cost, ll length) {
        if(cost >= s && cost <= t && length == l) {
            ans[v] = 1;
            return;
        }
        if(length == l) return;
        for(auto [child, c] : adj[v]) {
            dfs(child, cost + c, length + 1);
        }
    };

    dfs(1, 0, 0);

    for (ll i = 1; i <= n; i++) if(ans[i]) cout << i << " ";
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