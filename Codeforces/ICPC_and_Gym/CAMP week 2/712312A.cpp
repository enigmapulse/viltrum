#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e12;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> wt(n + 1); inarr(wt, n);

    vector<ll> dp(k + 1, INF);
    dp[0] = 0;
    
    for (ll i = 1; i <= n; i++) {
        for (ll w = wt[i]; w <= k; w++) {
            dp[w] = min(dp[w], 1 + dp[w - wt[i]]);
        }
    }

    ll min_coins = dp[k];
    if(min_coins == 1 || 2 * min_coins <= k) cout << "stable" << endl;
    else cout << "unstable" << endl;
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