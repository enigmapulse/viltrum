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
    vector<ll> p(n + 1);
    for (ll i = 2; i <= n; i++) cin >> p[i];
    vector<vector<ll>> adj(n + 1);
    for (ll i = 2; i <= n; i++) {
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    
    vector<ll> ans(n + 1), h(n + 1);

    auto dfs = [&] (auto&& dfs, ll v, ll p) -> void {
       ll val = 0, cnt = 0;
       vector<ll> ch;
        for(auto child : adj[v]) {
            if(child == p) continue;
            cnt++;
            dfs(dfs, child, v);
            val += ans[child];
            ch.push_back(h[child]);
        }
        if (ch.empty()) {
            ans[v] = 1;
            h[v] = 1;
            return;
        }
        sort(all(ch));
        ans[v] = val + 1 + (cnt > 1 ? ch[ch.size() - 2] : 0);
        h[v] = *ch.rbegin() + 1;
    };
    dfs(dfs, 1, -1);

    cout << ans[1] << endl;
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