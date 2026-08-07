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
    ll n, m; cin >> n >> m;
    vector<pll> edges(m);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        edges[i] = {min(u, v), max(u, v)};
    }
    
    sort(all(edges));
    edges.erase(unique(all(edges)), edges.end());
    ll tot = edges.size();

    vector<ll> deg(n + 1, 0);
    for(auto [u, v] : edges) {
        deg[u]++; deg[v]++;
    }
    vector<ll> d = deg;

    ll cnt = 0;
    sort(all(deg));
    for (ll i = 1; i <= n; i++) {
        auto it = lower_bound(deg.begin() + i + 1, deg.end(), tot - deg[i]);
        cnt += deg.end() - it;
    }
    for(auto [u, v] : edges) {
        if(d[u] + d[v] == tot) cnt--;
    }
    cout << cnt << endl;
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