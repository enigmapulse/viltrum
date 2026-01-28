#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<string> grid(n); inarr(grid, n);

    vector<vector<ll>> dp(n, vector<ll> (n + 1, 0)), mn(n, vector<ll> (n + 1, 0));
    
    for (ll i = 0; i < n; i++) {
        ll cnt1 = 0;
        for (ll j = 1; j <= n; j++) {
            cnt1 += (grid[i][j-1] == '#');
            dp[i][j] += cnt1;
        }
        
        ll cnt2 = 0;
        for (ll j = n - 1; j >= 0; j--) {
            cnt2 += (grid[i][j] == '.');
            dp[i][j] += cnt2;
        }
    }
    
    for (ll i = n - 2; i >= 0; i--) {
        mn[i + 1][0] = dp[i + 1][0];
        for (ll j = 1; j <= n; j++) {
            mn[i + 1][j] = min(mn[i + 1][j - 1], dp[i + 1][j]);
        }
        
        for (ll j = 0; j <= n; j++) dp[i][j] += mn[i + 1][j];
    }
    
    cout << *min_element(all(dp[0])) << endl;
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