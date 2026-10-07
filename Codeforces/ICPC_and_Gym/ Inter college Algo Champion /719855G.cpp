#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define ppll pair<ll, pll>

using namespace std;

struct DSU {
    vector<ll> parent;
    vector<ll> size;

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> p(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> p[i];
    vector<ppll> wt(m);
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        wt[i] = {w, {u, v}};
    }
    sort(all(wt), greater());

    // counter of elements not yet matched
    ll ct = 0;
    for (ll i = 1; i <= n; i++) ct += (p[i] != i);

    for(auto [w, pr] : wt) {

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