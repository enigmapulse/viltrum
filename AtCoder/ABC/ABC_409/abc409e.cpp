#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> f(n + 1); inarr(f, n);
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    function <ll(ll, ll)> dfs = [&] (ll v, ll p) {
        ll ret = 0, val = 0;
        for(auto [child, weight] : adj[v]) {
            if(child == p) continue;
            ll x = dfs(child, v);
            ret += weight * abs(f[child]) + x;
            val += f[child];
        }
        f[v] += val;
        return ret;
    };

    cout << dfs(1, -1) << endl;
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