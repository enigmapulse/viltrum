#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll> (3, 0));
    for (ll i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

    vector<vector<ll>> dp(n, vector<ll> (3, 0));
    dp[0][0] = a[0][0]; dp[0][1] = a[0][1]; dp[0][2] = a[0][2];
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j < 3; j++) {
            dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + a[i][j];   
        }
    }
    
    cout << *max_element(all(dp[n - 1])) << endl;
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