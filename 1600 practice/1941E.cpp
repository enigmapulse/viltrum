#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k, d; cin >> n >> m >> k >> d;
    vector<vector<ll>> grid(n, vector<ll> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];   
        }
    }
    
    vector<vector<ll>> dp(n, vector<ll> (m));
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        multiset<ll> s; dp[i][0] = 1;
        s.insert(1);
        for (ll j = 1; j < m; j++) {
            auto it = s.begin();
            dp[i][j] = grid[i][j] + 1 + *it;
            s.insert(dp[i][j]);
            if(j >= d + 1) s.erase(s.find(dp[i][j - d - 1]));
        }
        ans[i] = dp[i][m - 1];
    }
    
    for (ll i = 1; i < n; i++) ans[i] += ans[i - 1];
    ll mn = 1e12;
    for (ll i = k - 1; i < n; i++) {
        ll val = ans[i] - (i >= k ? ans[i - k] : 0);
        mn = min(mn, val);
    }
    
    cout << mn << endl;
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