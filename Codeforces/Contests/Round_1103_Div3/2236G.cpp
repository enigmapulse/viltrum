#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> tin(n + 1), tout(n + 1), h(n + 1, 0); ll timer = 0;
    vector<vector<ll>> up(n + 1, vector<ll> (20, 0));
    auto dfs = [&] (auto&& dfs, ll v, ll p) -> void {
        tin[v] = timer++;
        up[v][0] = p; 
        for(auto child : adj[v]) {
            if(child == p) continue;
            h[child] = h[v] + 1;
            dfs(dfs, child, v);
        }
        tout[v] = timer++;
    };
    dfs(dfs, 1, 1);

    for (ll j = 1; j < 20; j++) {
        for (ll i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    auto chk = [&] (ll u, ll v) {
        return (tin[u] <= tin[v]) && (tout[v] <= tout[u]);
    };

    auto lca = [&] (ll u, ll v) {
        if(chk(u, v)) return u;
        else if(chk(v, u)) return v;
        else {
            for (ll b = 19; b >= 0; b--) {
                if(!chk(up[u][b], v)) u = up[u][b];
            }
            return up[u][0];
        }
    };

    auto dist = [&] (ll u, ll v) {
        return h[u] + h[v] - 2 * h[lca(u, v)];
    };

    struct node {
        ll u, v, d;
    };
    vector<ll> col(n + 1, true);
    auto merge = [&] (node a, node b) -> node {
        if(a.u == -1) return b;
        if(b.u == -1) return a;
        vector<ll> pts = {a.u, a.v, b.u, b.v};
        ll mx = 0, nu, nv;
        for (ll i = 0; i < 4; i++) {
            for (ll j = i + 1; j < 4; j++) {
                if(dist(pts[i], pts[j]) >= mx) {
                    mx = dist(pts[i], pts[j]);
                    nu = pts[i], nv = pts[j];
                }
            }
        }
        return {nu, nv, mx};
    };
    
    vector<node> t; t.assign(4 * (n + 1), {-1, -1, -1});

    auto build = [&] (auto&& build, ll v, ll tl, ll tr) -> void {
        if(tl == tr) {t[v] = {tl, tl, 0}; return;}
        ll mid = tl + (tr - tl)/2;
        build(build, 2*v, tl, mid);
        build(build, 2*v + 1, mid + 1, tr);
        t[v] = merge(t[2*v], t[2*v + 1]);
    };
    
    auto update = [&] (auto&& update, ll v, ll tl, ll tr, ll pos) -> void {
        if(tl == tr) {
            if(!col[tl]) t[v] = {-1, -1, -1};
            else t[v] = {tl, tl, 0};
            return;
        }
        else {
            ll mid = (tl + tr)/2;
            if(pos <= mid) update(update, 2*v, tl, mid, pos);
            else update(update, 2*v + 1, mid + 1, tr, pos);
            t[v] = merge(t[2*v], t[2*v + 1]);
        }
    };

    build(build, 1, 1, n);

    ll q; cin >> q;
    while(q--) {
        ll x; cin >> x;
        col[x] = !col[x];
        update(update, 1, 1, n, x);
        cout << t[1].d << endl;
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