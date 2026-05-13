#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            if(i == 0 || j == 0) {dp[i][j] = 0; continue;}
            if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);        
        }
    }
    
    string ans;
    ll curX = n, curY = m;
    while(curX != 0 && curY != 0) {
        if(s[curX - 1] == t[curY - 1]) {
            ans += s[curX - 1];
            curX--; curY--;
        }
        else {
            if(dp[curX][curY] == dp[curX - 1][curY]) curX--;
            else curY--;
        }
    }
    reverse(all(ans));

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