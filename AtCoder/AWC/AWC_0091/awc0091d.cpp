#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e16;

using namespace std;

inline ll f(ll x) {
    return (x * (x + 1)) / 2;
}

struct DSU {
    vector<ll> parent;
    vector<ll> size;
    vector<bool> active;

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        active.assign(n + 1, false);
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    // returns delta to the total subsegments count
    ll unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            ll prev = f(size[a]) + f(size[b]);
            size[a] += size[b];
            ll nw = f(size[a]);
            return nw - prev;
        }
        return 0;
    }

    ll flip(ll x) {
        active[x] = true;
        ll delta = 1;
        if(x < active.size() - 1 && active[x + 1]) delta += unite(x, x + 1);
        if(x > 0 && active[x - 1]) delta += unite(x, x - 1);
        return delta;
    }
};

bool multipleTests = false;

void solve() {
    ll n, q, k; cin >> n >> q >> k;

    // required time to turn dark
    vector<pll> req;
    for (ll i = 0; i < n; i++) {
        ll a, d; cin >> a >> d;
        if(a <= k) req.push_back({0, i});
        else if(d == 0) req.push_back({INF, i});
        else req.push_back({(a - k + d - 1) / d, i});
    }
    sort(all(req));

    // offline processing
    vector<ll> ans(q, 0);
    vector<pll> query;
    for (ll i = 0; i < q; i++) {
        ll x; cin >> x;
        query.push_back({x, i});
    }
    sort(all(query));

    ll tot = 0; // total subsegments count
    ll idx = 0; // pointer to the required time array 
    DSU st(n); // street lights
    for(auto [t, id] : query) {
        while(idx < n && req[idx].first <= t) {
            tot += st.flip(req[idx].second);
            idx++;
        }
        ans[id] = tot;
    }

    for(auto res : ans) cout << res << endl;
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