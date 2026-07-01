#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

vector<bool> sq(1000001, false);

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1); inarr(a, n);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> subtree(n + 1, 0);
    auto dfs = [&] (auto&& dfs, ll v, ll p) -> void{
        ll sz = 1;
        for(auto child : adj[v]) {
            if(child == p) continue;
            dfs(dfs, child, v);
            sz += subtree[child];
        }
        subtree[v] = sz;
    };
    dfs(dfs, 1, -1);

    ll ans = 0;
    auto calc = [&] (auto&& calc, ll v, ll p) -> void{
        vector<ll> vals; vals.reserve(adj[v].size());
        for(auto child : adj[v]) {
            if(child == p) {
                vals.push_back(n - subtree[v]);
                continue;
            }
            vals.push_back(subtree[child]);
            calc(calc, child, v);
        }
        if(!sq[a[v]]) return;
        ll single = 0, pair = 0, triple = 0;
        for(auto cnt : vals) {
            triple += pair * cnt;
            pair += single * cnt;
            single += cnt;
        }
        ans += triple + pair;
    };
    calc(calc, 1, -1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (ll i = 0; i * i <= 1000000; i++) sq[i * i] = true;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}