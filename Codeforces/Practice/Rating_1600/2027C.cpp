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

    map<ll, vector<ll>> mp; // increments possible for each value
    for (ll i = 0; i < n; i++) {
        if(a[i] - (n - i) >= 0) mp[a[i] - (n - i)].push_back(i);
    }
    
    ll mx = 0; map<ll, bool> vis;
    auto dfs = [&] (auto&& dfs, ll v) {
        mx = max(mx, v); vis[v] = true;
        if(!mp.contains(v)) return;
        for(auto inc : mp[v]) {
            if(inc != 0 && !vis[v + inc]) dfs(dfs, v + inc);
        }
    };
    dfs(dfs, 0);

    cout << n + mx << endl;
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