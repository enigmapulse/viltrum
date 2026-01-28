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
    vector<ll> deg(n + 1, 0);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v); deg[u]++;
        adj[v].push_back(u); deg[v]++;
    }
    
    // in first choice it matters which vertex of max degree we
    // choose. Among those vertices we will choose the one which 
    // reduces the max degree for 2nd step the least
    set<ll> s;
    ll maxdeg1 = *max_element(all(deg));
    for (ll i = 1; i <= n; i++) {
        if(deg[i] == maxdeg1) s.insert(i);
    }

    ll remove_v = 0, min_shared = 1e9;
    for(auto v : s) {
        ll cnt = 0;
        for(auto n : adj[v]) {
            if(s.find(n) != s.end()) ++cnt;
        }
        if(cnt < min_shared) {
            remove_v = v;
            min_shared = cnt;
        }
    }

    for(auto n : adj[remove_v]) deg[n]--;
    deg[remove_v] = 0;
    
    // second choice is greedy and doesn't matter
    ll maxdeg2 = *max_element(all(deg));

    cout << maxdeg1 + maxdeg2 - 1 << endl;
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