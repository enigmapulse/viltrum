#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(i);
    }
    
    pair<ll, ll> f = {0, 0};
    vector<ll> vis(n + 1, false);
    for (ll i = 1; i <= n; i++) {
        for(auto v : adj[i]) {
            if(vis[i] || vis[v]) continue;
            cout << "? " << i << " " << v << endl << flush;
            vis[i] = true; vis[v] = true;
            ll o; cin >> o;
            if(o == 1) {f = {i, v}; break;}
        }
    }

    if(f.first == 0) {
        for (ll i = 1; i <= n; i++) {
            if(!vis[i]) {
                cout << "! " << i << endl << flush;
                return;
            }
        }
    } 
    
    cout << "? " << f.first << " " << f.first << endl << flush;
    ll o; cin >> o;
    if(o == 1) cout << "! " << f.first << endl << flush;
    else cout << "! " << f.second << endl << flush;
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