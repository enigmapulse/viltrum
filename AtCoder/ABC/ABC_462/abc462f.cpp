#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s; ll n = s.size();
    string t = " " + s;
    ll cnt = 0;
    for (ll i = 1; i <= n - 2; i++) {
        string cur = t.substr(i, 3);
        if(cur == "ABC") cnt++;
    }
    
    ll k; cin >> k;
    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, INF));
    for (ll i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    
    for (ll j = 1; j <= k; j++) {
        for (ll i = 3; i <= n; i++) {
            ll cnt = 0;
            cnt += (t[i] == 'C');
            cnt += (t[i - 1] == 'B');
            cnt += (t[i - 2] == 'A');
            if(cnt == 3) dp[i][j] = dp[i - 3][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i - 3][j - 1] + 3 - cnt);
        }
    }
    if(dp[n][k] == INF) cout << -1 << endl;
    else cout << dp[n][k] << endl;
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