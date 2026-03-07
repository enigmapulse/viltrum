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
    vector<ll> a(n); inarr(a, n);

    vector<vector<ll>> dp(n, vector<ll> (n + 1, 0));
    for (ll i = 0; i < n; i++) dp[i][1] = a[i];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= n; j++) {
            ll choice1 = ((i > 0) ? dp[i - 1][j] : 0);
            ll choice2 = ((i > 0 && j > 0) ? dp[i - 1][j - 1] + a[i] : 0);
            ll choice3 = ((i > 0 && j > 1) ? dp[i - 1][j - 2] + 2 * a[i] : 0);
            dp[i][j] = max({choice1, choice2, choice3});
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