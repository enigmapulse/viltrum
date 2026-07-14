#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e18;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a0(n), a1(n);
    for (ll i = 0; i < n; i++) {
        cin >> a0[i] >> a1[i];
        if(i != 0) {
            a0[i] += a0[i - 1];
            a1[i] += a1[i - 1];
        }
    }

    vector<vector<ll>> dp(n, vector<ll> (k + 1, 0));
    for (ll i = 0; i < n; i++) dp[i][0] = a0[i];
    for (ll ops = 1; ops <= k; ops++) dp[0][ops] = max(a0[0], a1[0]);
    
    ll prev_mx = -INF;
    for (ll ops = 1; ops <= k; ops++) {
        prev_mx = dp[0][ops - 1] - a1[0];
        for (ll i = 1; i < n; i++) {
            dp[i][ops] = dp[i - 1][ops] + a0[i] - a0[i - 1];
            dp[i][ops] = max(dp[i][ops], a1[i]);
            dp[i][ops] = max(dp[i][ops], prev_mx + a1[i]);
            prev_mx = max(prev_mx, dp[i][ops - 1] - a1[i]);
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