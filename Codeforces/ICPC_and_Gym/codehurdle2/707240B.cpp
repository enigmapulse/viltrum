#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = false;
ll dp[105][5055][105] = {};

void solve() {
    ll n, m, k; cin >> n >> m >> k;

    dp[0][0][0] = 1;
    if(m < n || (m > (n * (n + 1))/2)) {
        cout << 0 << endl;
        return;
    }

    for (ll idx = 1; idx <= n; idx++) {
        // suffix sum calculation
        for (ll cnt = idx - 1; cnt <= m; cnt++) {
            for (ll len = min(idx - 1, k); len >= 0; len--) {
                dp[idx - 1][cnt][len] = (dp[idx - 1][cnt][len] + dp[idx - 1][cnt][len + 1]) % MOD;
            }
        }

        for (ll len = 1; len <= min(idx, k); len++) {
            for (ll cnt = len; cnt <= m; cnt++) {
                ll added = dp[idx - 1][cnt - len][len - 1] - dp[idx - 1][cnt - len][len];
                added = (added + MOD) % MOD;
                dp[idx][cnt][len] = (added * (k - len + 1)) % MOD;
                dp[idx][cnt][len] = (dp[idx - 1][cnt - len][len] + dp[idx][cnt][len]) % MOD;
            }
        }
    }
    
    ll ans = 0;
    for (ll len = 1; len <= min(n, k); len++) {
        ans = (ans + dp[n][m][len]) % MOD;
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