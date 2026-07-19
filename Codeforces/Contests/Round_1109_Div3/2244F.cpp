#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e12;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n + 1, 0);
    for (ll i = 2; i <= n; i++) cin >> p[i];
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> a[i];
    
    vector<vector<ll>> adj(n + 1);
    for (ll i = 2; i <= n; i++) {
        adj[p[i]].push_back(i);
    }
    
    vector<ll> mn(n + 1, INF);
    auto dfs = [&] (auto&& dfs, ll v) -> void {
        ll mn_val = INF;
        for(auto child : adj[v]) {
            dfs(dfs, child);
            mn_val = min(mn_val, mn[child]);
        }
        if(mn_val == INF) mn[v] = a[v]; 
        else mn[v] = mn_val;
    };
    dfs(dfs, 1);

    vector<ll> res;
    auto chk = [&] (auto&& chk, ll v) -> void {

        if(adj[v].empty()) {
            res.push_back(a[v]);
            return;
        }

        ll mn_idx = -1, mn_val = INF;
        for (ll i = 0; i < adj[v].size(); i++) {
            if(mn[adj[v][i]] < mn_val) {
                mn_val = mn[adj[v][i]];
                mn_idx = i;
            }
        }
        
        for (ll j = 0; j < adj[v].size(); j++) {
            ll idx = (mn_idx + j) % (adj[v].size());
            chk(chk, adj[v][idx]);
        }
    };
    chk(chk, 1);

    vector<ll> temp = res;
    sort(all(temp));
    if(res == temp) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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