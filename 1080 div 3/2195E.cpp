#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> children(n + 1);
    vector<vector<ll>> adj(n + 1); adj[0].push_back(1);
    for (ll i = 1; i <= n; i++) {
        ll u, v; cin >> u >> v;
        if(u != 0) {
            children[i].first = u, children[i].second = v;
            adj[i].push_back(u); adj[i].push_back(v);
        }
    }
    
    vector<ll> ans(n + 1, 0), sm(n + 1, 0); ans[1] = 2 * n - 1;

    function<void(ll)> dfs = [&] (ll v) {
        ll sum = 1;
        for(auto c : adj[v]) {
            dfs(c);
            sum += sm[c]; sum %= MOD;
        }
        sm[v] = sum; sm[v] %= MOD;
    };
    dfs(0);

    function<void(ll)> dp = [&] (ll v) {
        for(auto c : adj[v]) {
            ans[c] = ans[v] + 2 * sm[c] - 1; ans[c] %= MOD;
            dp(c);
        }
    };
    dp(1);

    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
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