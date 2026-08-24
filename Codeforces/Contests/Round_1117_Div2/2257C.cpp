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
    vector<ll> p(n + 1, 1);
    for (ll i = 2; i <= n; i++) cin >> p[i];
    
    ll m; cin >> m;
    vector<ll> cnt(n + 1, 0);
    set<ll> nodes;
    for (ll i = 0; i < m; i++) {
        ll x; cin >> x;
        nodes.insert(x);
        cnt[x]++;
    }

    for (ll i = n; i >= 1; i--) {
        cnt[p[i]] += cnt[i];
    }
    
    vector<vector<ll>> adj(n + 1);
    for (ll i = 2; i <= n; i++) {
        adj[p[i]].push_back(i);
    }
    
    vector<ll> ans;
    auto dfs = [&] (auto&& dfs, ll v, ll p) -> void {
        vector<ll> active;
        for(auto ch : adj[v]) {
            if(cnt[ch] != 0) active.push_back(ch);
        }
        if(nodes.find(v) != nodes.end()) {
            for(auto ch : active) ans.push_back(ch);
        }
        else {
            if(active.size() > 1) {
                for(ll i = 1; i < active.size(); i++) ans.push_back(active[i]);
            }
        }
        for(auto ch : adj[v]) {
            dfs(dfs, ch, v);
        }
    };
    dfs(dfs, 1, -1);

    cout << ans.size() << " ";
    for(auto x : ans) cout << x << " ";
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