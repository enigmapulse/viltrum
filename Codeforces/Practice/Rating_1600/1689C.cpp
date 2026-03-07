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
    for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(adj[1].size() == 1) {
        cout << n - 2 << endl;
        return;
    }
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    
    ll mn = LLONG_MAX; ll cnt = 1;
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        for(auto child : adj[v]) {
            if(child == p) continue;
            cnt++; dfs(child, v);
        }
        if(adj[v].size() == 1 && v != 1) mn = min(mn, 2 * cnt - 1);
        else if(adj[v].size() == 2 && v != 1) mn = min(mn, 2 * cnt);
        cnt--;
    };

    dfs(1, -1);

    cout << n - mn << endl;
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