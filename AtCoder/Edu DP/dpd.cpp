#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, w; cin >> n >> w;
    vector<pll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll u, v; cin >> u >> v;
        a[i] = {v, u};
    }

    vector<vector<ll>> dp(n + 1, vector<ll> (w + 1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= w; j++) {
            if(j < a[i].second) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].second] + a[i].first);
        }
    }
    cout << dp[n][w] << endl;
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