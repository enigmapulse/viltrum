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

    vector<ll> ord;
    function <void(ll, ll)> dfs = [&] (ll v, ll p) {
        ord.push_back(v);
        for(auto child : adj[v]) {
            if(child == p) continue;
            dfs(child, v);
        }
    };
    
    pair<ll, ll> f = {0, 0};
    for (ll i = 0; i < n; i += 2) {
        if(i == n - 1) {
            cout << "! " << ord[i] << endl << flush;
            return;
        }
        cout << "? " << ord[i] << " " << ord[i + 1] << endl << flush;
        ll o; cin >> o;
        if(o == 1) {
            f = {ord[i], ord[i + 1]};
            break;
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