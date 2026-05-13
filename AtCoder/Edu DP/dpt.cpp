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
    int n; cin >> n;
    string s; cin >> s;

    vector<ll> pre(n, 1);
    vector<vector<ll>> dp(n, vector<ll> (n, 0)); dp[0][0] = 1;

    for (ll i = 1; i < n; i++) {
        char ch = s[i - 1];
        for (ll j = 0; j <= i; j++) {
            if(ch == '<') {
                if(j == 0) continue;
                dp[i][j] = pre[j - 1] % MOD;
            }
            else {
                if(j == n - 1) continue;
                dp[i][j] = (pre[i - 1] - (j > 0 ? pre[j - 1] : 0) + MOD) % MOD;
            }
        }

        for (ll j = 0; j < n; j++) {
            pre[j] = dp[i][j] + (j > 0 ? pre[j - 1] : 0);
            pre[j] = pre[j] % MOD;
        }
    }
    
    ll sm = 0;
    for (ll j = 0; j < n; j++) {
        sm = (sm + dp[n - 1][j]) % MOD;
    }
    cout << sm % MOD << endl;
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