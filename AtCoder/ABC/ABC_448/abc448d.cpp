#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> c(n + 1); inarr(c, n);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> ans(n + 1, 0);
    
    map<ll, ll> mp; // freq of values on nodes we have visited till now
    ll cnt = 0; // number of elements encountered till now which have freq greater than 2
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        mp[c[v]]++; cnt += (mp[c[v]] > 1);
        if(cnt) ans[v] = 1;
        for(auto child : adj[v]) {
            if(child == p) continue;
            dfs(child, v);
        }
        cnt -= (mp[c[v]] > 1); mp[c[v]]--;
    };

    dfs(1, -1);

    for (ll i = 1; i <= n; i++) {
        if(ans[i] == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
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