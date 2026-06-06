#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    vector<vector<ll>> dp(n, vector<ll> (k + 1, 0));
    for (ll i = 0; i < n; i++) {
        dp[i][0] = a[i];
        if(i != 0) dp[i][0] += dp[i - 1][0];
    }
    
    for (ll ops = 1; ops <= k; ops++) {
        for (ll i = 0; i < n; i++) {
            dp[i][ops] = (i > 0 ? dp[i - 1][ops] : 0ll) + a[i]; 
            if(i == 0) continue;
            ll mn = a[i], cnt = 1;
            for (ll j = 1; j <= min(ops, i); j++) {
                mn = min(mn, a[i - j]); cnt++;
                dp[i][ops] = min(dp[i][ops], (i - j > 0 ? dp[i - j - 1][ops - j] : 0ll) + cnt * mn);
            }
        }
    }
    
    cout << dp[n - 1][k] << endl;
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