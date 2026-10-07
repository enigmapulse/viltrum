#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    inarr(a, n);

    vector<vector<ll>> dp(2, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) {
        dp[0][i] = -a[i];
        dp[1][i] = a[i];
    }

    for (ll i = 1; i < n; i++) {
        dp[0][i] = -a[i];
        dp[0][i] = max(dp[0][i], max(dp[0][i - 1], dp[1][i - 1] - a[i]));
        dp[1][i] = a[i];
        dp[1][i] = max(dp[1][i], max(dp[1][i - 1], dp[0][i - 1] + a[i]));
    }

    cout << max(*max_element(all(dp[0])), *max_element(all(dp[1]))) << endl;
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