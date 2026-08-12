#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, st, en) for (int _i = st; _i < (en); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e18;

using namespace std;

struct DSU {
    vector<ll> parent;
    vector<ll> size;
    vector<ll> sum;

    DSU(ll n, vector<ll>& c) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        sum.assign(n + 1, 0);
        iota(all(parent), 0);
        sum = c;
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
            sum[a] += sum[b];
            return true;
        }
        return false;
    }
};

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    ll V, K, C_req; cin >> V >> K >> C_req;

    vector<ll> a(n + 1); inarr(a, 1, n + 1);

    // time when each node gets infected
    vector<ll> time(n + 1, INF); time[0] = 0;
    queue<pll> q;
    for (ll i = 0; i < V; i++) {
        ll x; cin >> x;
        q.push({0, x});
        time[x] = 0;
    }

    vector<ll> core(K); inarr(core, 0, K);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    while(!q.empty()) {
        auto [t, idx] = q.front(); q.pop();
        for(auto child : adj[idx]) {
            if(time[child] <= t + 1) continue;
            time[child] = t + 1;
            q.push({t + 1, child});
        }
    }

    auto chk = [&] (ll x) -> bool {
        DSU st(n, a);
        for (ll node = 1; node <= n; node++) {
            if(time[node] <= x) continue;
            for(auto neighbor : adj[node]) {
                if(time[neighbor] <= x) continue;
                st.unite(node, neighbor);
            }
        }
        // all nodes are active
        for(auto y : core) if(time[y] <= x) return false;
        set<ll> par;
        for(auto y : core) par.insert(st.find(y));
        if(par.size() > 1) return false;
        auto p = *par.begin();
        return (st.sum[p] >= C_req);
    };
 
    ll lo = 0, hi = n;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }
    if(chk(lo)) cout << lo << endl;
    else cout << -1 << endl;
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