#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e17;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    ll sz = 2 * n;
    vector<ll> h(sz); inarr(h, sz);

    // dp[i][j] gives the best pairing for chord from i to j clockwise
    vector<vector<ll>> dp(sz, vector<ll>(sz, INF));

    // base case
    for (ll i = 0; i < sz; i++) {
        ll nxt = (i + 1) % sz;
        ll cost = abs(h[nxt] - h[i]);
        dp[i][nxt] = cost;
    }
    
    for (ll len = 4; len <= sz; len += 2) {
        for (ll idx = 0; idx <= sz - len; idx++) {
            ll nxt = idx + len - 1;

            ll direct = dp[idx + 1][nxt - 1] + abs(h[idx] - h[nxt]);
            dp[idx][nxt] = min(dp[idx][nxt], direct);

            for (ll cut = idx + 1; cut < nxt; cut+=2) {
                dp[idx][nxt] = min(dp[idx][nxt], dp[idx][cut] + dp[cut + 1][nxt]);
            }
        }
    }
    
    cout << dp[0][sz - 1] << endl;
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