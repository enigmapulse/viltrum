#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> grid(n); inarr(grid, n);

    vector<vector<ll>> dp(n, vector<ll> (m, 0));
    dp[0][0] = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == '#') {dp[i][j] = 0; continue;}
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;

            // cerr << dp[i][j] << " ";
        }
        // cerr << endl;
    }
    
    cout << dp[n - 1][m - 1] << endl;  
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