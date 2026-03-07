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
    vector<ll> a(n); inarr(a, n);

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string ans(n, '0');
    
    for (ll i = 1; i <= n; i++) {
        ll v = a[i - 1];

        map<ll, ll> mp;
        for(auto child : adj[i]) {
            if(a[child - 1] == v) ans[v - 1] = '1';
            mp[a[child - 1]]++;
        }

        for(auto [val, cnt] : mp) {
            if(cnt > 1) ans[val - 1] = '1';
        }
    }
    
    cout << ans << endl;
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