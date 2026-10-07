#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;

    vector<ll> dp(n + 1, 0);
    dp[1] = 1; dp[0] = 1;
    for(ll i = 2; i <= min(k + 1, n); i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
    }
    for(ll j = min(k + 1, n) + 1; j <= n; j++) {
        for(ll rem = j; rem >= 1; rem--) {
            if(rem + k <= j) dp[j] = (dp[j] + (2 * dp[rem - 1])) % MOD;
            else dp[j] = (dp[j] + dp[rem - 1]) % MOD;
        }
        dp[j] = (dp[j] - 1 + MOD) % MOD;
    }

    cout << dp[n] << endl;
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