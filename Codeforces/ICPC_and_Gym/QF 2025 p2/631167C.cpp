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

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (2, vector<ll> (3, 0)));
    dp[0][0][0] = 1;

    for (ll i = 0; i < n; i++) {
        for (ll s = 0; s < 2; s++) {
            for (ll t = 0; t < 3; t++) {
                // put an s after i
                if(s != 1) {
                    dp[i + 1][s + 1][0] = (dp[i + 1][s + 1][0] + dp[i][s][t]) % MOD;
                }
                // put a t after i
                if(t != 2) {
                    dp[i + 1][0][t + 1] = (dp[i + 1][0][t + 1] + dp[i][s][t]) % MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (ll s = 0; s < 2; s++) {
        for (ll t = 0; t < 3; t++) {
            ans = (ans + dp[n][s][t]) % MOD;
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