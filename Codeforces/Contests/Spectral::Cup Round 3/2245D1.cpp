#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> res(n + 1, 0);
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll o, u, v; cin >> o >> u >> v;
        if(u == v) {
            if(o == 2) res[u] = -1;
            continue;
        }
        adj[u].push_back({v, o});
    }
    
    vector<vector<ll>> edges(n + 1);
    vector<ll> inDegree(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        for(auto [nxt, ops] : adj[i]) {
            ll curr = res[i] + res[nxt];
            if((curr == -2 && ops == 1) || (curr == 0 && ops == 2)) {
                cout << "NO" << endl;
                return;
            }
            if(curr == -1) {
                if(ops == 1) {
                    if (res[i] == 0) {edges[nxt].push_back(i); inDegree[i]++;}
                    else {edges[i].push_back(nxt); inDegree[nxt]++;}
                }
                else {
                    if (res[i] == 0) {edges[i].push_back(nxt); inDegree[nxt]++;}
                    else {edges[nxt].push_back(i); inDegree[i]++;}
                }
            }
        }
    }

    queue<ll> q;
    for(ll i = 1; i <= n; i++) if(inDegree[i] == 0) q.push(i);
    ll cnt = 1; ll nodes = 0;

    while(!q.empty()) {
        auto u = q.front();
        q.pop(); nodes++;
        if(res[u] == 0) res[u] = cnt++;
        else {res[u] = -1 * cnt; cnt++;}
        for(auto v : edges[u]) {
            inDegree[v]--;
            if(inDegree[v] == 0) q.push(v);
        }
    }

    if(nodes < n) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (ll i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
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