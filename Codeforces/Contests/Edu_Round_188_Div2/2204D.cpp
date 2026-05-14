#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll> comp;
    vector<ll> col(n + 1, -1);
    bool chk = true;
    function<void(ll)> dfs = [&] (ll v) {
        comp.push_back(v);
        for(auto child : adj[v]) {
            if(col[child] == -1) {
                col[child] = col[v] ^ 1;
                dfs(child);
            } else if(col[child] == col[v]) {
                chk = false;
            }
        }
    };

    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        if(col[i] == -1) {
            col[i] = 0;
            comp.clear();
            chk = true;
            dfs(i);
            if(chk) {
                ll cn = 0;
                for(auto x : comp) {
                    if(col[x] == 0) cn++;
                }
                cnt += max(cn, (ll)comp.size() - cn);
            }
        }
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