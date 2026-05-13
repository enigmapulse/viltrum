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
    string s; cin >> s;
    ll k; cin >> k;
    ll n = s.size();

    ll dp[n + 1][2][k]; // count of nums considering first i characters, w/wo tight, modulo k 
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;

    /*
    dp[i - 1][1][k] -> dp[i][1][k + lim]
    dp[i - 1][1][k] -> dp[i][0][k + j] j < lim
    dp[i - 1][0][k] -> dp[i][0][k + j] j from 0 ... 9
    */
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            ll lim = s[i] - '0';
            {
                dp[i + 1][1][(j + lim) % k] = (dp[i + 1][1][(j + lim) % k] + dp[i][1][j]) % MOD;
                for (ll dig = 0; dig < lim; dig++) {
                    dp[i + 1][0][(j + dig) % k] = (dp[i + 1][0][(j + dig) % k] + dp[i][1][j]) % MOD;
                }
            }

            {
               for (ll dig = 0; dig < 10; dig++) {
                    dp[i + 1][0][(j + dig) % k] = (dp[i + 1][0][(j + dig) % k] + dp[i][0][j]) % MOD;
                }
            }
        }
    }
    

    cout << (dp[n][0][0] + dp[n][1][0] - 1 + MOD) % MOD << endl;
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