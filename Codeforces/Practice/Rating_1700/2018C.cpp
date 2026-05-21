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
        adj[v].push_back(u);
    }
    
    vector<ll> d(n + 1, 0), dl(n + 1, 0);
    function<void(ll, ll)> dfs = [&] (ll v, ll p) {
        dl[v] = d[v];
        for(auto ch : adj[v]) {
            if(ch == p) continue;
            d[ch] = d[v] + 1;
            dfs(ch, v);
            dl[v] = max(dl[ch], dl[v]);
        }
    };
    dfs(1, -1);

    vector<ll> cnt(n + 2, 0);
    for (ll i = 1; i <= n; i++) {
        cnt[d[i]] += 1; cnt[dl[i] + 1] -= 1;
    }
    for (ll i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    
    cout << n - *max_element(all(cnt)) << endl;
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