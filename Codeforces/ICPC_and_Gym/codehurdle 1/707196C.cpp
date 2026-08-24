#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e12;

using namespace std;
bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    inarr(a, n); inarr(b, n);

    vector<vector<ll>> dp(m + 1, vector<ll> (n + 1, INF));

    // base cases
    dp[0][1] = 0;
    for (ll i = 2; i <= n; i++) {
        dp[0][i] = dp[0][i - 1] + a[i - 1];
    }
    for (ll i = 1; i <= m; i++) {
        dp[i][1] = 0ll;
    }
    
    for (ll jmps = 1; jmps <= m; jmps++) {
        deque<ll> dq;
        for (ll idx = 2; idx <= n; idx++) {
            ll l = max(idx - k, 1ll);
            while(!dq.empty() && dq.front() < l) dq.pop_front();
            while(!dq.empty() && dp[jmps - 1][dq.back()] + b[dq.back()] >= dp[jmps - 1][idx - 1] + b[idx - 1]) dq.pop_back();
            dq.push_back(idx - 1);
            ll best = dp[jmps - 1][dq.front()] + b[dq.front()];

            dp[jmps][idx] = min(dp[jmps][idx - 1] + a[idx - 1], dp[jmps][idx]);
            dp[jmps][idx] = min(best + b[idx], dp[jmps][idx]);
        }
    }
    
    cout << dp[m][n] << endl;
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