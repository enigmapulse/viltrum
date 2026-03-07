#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, s; cin >> n >> s;
    vector<ll> a(n); inarr(a, n);

    vector<vector<pll>> dp(n, vector<pll> (2, {0, 0}));
    dp[0][0].F = dp[0][1].F = 0;
    dp[0][0].S = dp[0][1].S = a[0];

    for (ll i = 1; i < n - 1; i++) {
        pll curr = {0, 0}; curr = {max(s, a[i] - s), min(s, a[i] - s)};
        if(a[i] < s) curr = {a[i], 0};

        dp[i][0].S = curr.S;
        dp[i][0].F = min(dp[i - 1][0].F + (curr.F * dp[i - 1][0].S), dp[i - 1][1].F + (curr.F * dp[i - 1][1].S));

        swap(curr.F, curr.S);
        dp[i][1].S = curr.S;
        dp[i][1].F = min(dp[i - 1][0].F + (curr.F * dp[i - 1][0].S), dp[i - 1][1].F + (curr.F * dp[i - 1][1].S));
    }
    
    cout << min(dp[n - 2][0].F + (a[n - 1] * dp[n - 2][0].S), dp[n - 2][1].F + (a[n - 1] * dp[n - 2][1].S)) << endl;
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