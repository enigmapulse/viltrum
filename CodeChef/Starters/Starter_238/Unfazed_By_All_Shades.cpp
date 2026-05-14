#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;
const ll MOD = 998244353;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n, x; cin >> n >> x;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> leaves;
    for(ll i = 1; i <= n; ++i) {
        if(adj[i].size() == 1 || n == 1) leaves.push_back(i);
    }

    auto get_dists = [&](ll start) {
        vector<ll> dist(n + 1, -1);
        queue<ll> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            ll u = q.front(); q.pop();
            for (ll v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };

    vector<ll> dist_from_1 = get_dists(1);
    ll farthest_node = 1;
    for (ll i = 1; i <= n; i++) {
        if (dist_from_1[i] > dist_from_1[farthest_node]) farthest_node = i;
    }

    vector<ll> dist_from_farthest = get_dists(farthest_node);
    ll max_dist = 0;
    for (ll i = 1; i <= n; i++) {
        max_dist = max(max_dist, dist_from_farthest[i]);
    }

    vector<vector<ll>> max_dist_leaves(n + 1);
    for (ll u : leaves) {
        vector<ll> dists = get_dists(u);
        for (ll v : leaves) {
            if (u != v && dists[v] == max_dist) {
                max_dist_leaves[u].push_back(v);
            }
        }
    }

    ll ways = 1; // ways such that C != D
    vector<bool> assigned(n + 1, false);
    
    for (ll u : leaves) {
        ll cnt = 0;
        for (ll v : max_dist_leaves[u]) {
            if (assigned[v]) {
                cnt++;
            }
        }

        ll choices = x - cnt;
        if (choices < 0) choices = 0; 
        
        ways = (ways * choices) % MOD;
        assigned[u] = true;
    }

    ll non_leaves = n - leaves.size();
    ways = (ways * power(x, non_leaves)) % MOD;

    ll total_ways = power(x, n);
    ll ans = (total_ways - ways + MOD) % MOD;
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;`
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}