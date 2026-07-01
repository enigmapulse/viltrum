#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k, d; cin >> n >> m >> k >> d;
    vector<vector<ll>> a(n, vector<ll> (m, 0)), dp(n, vector<ll> (m, 0));

    for (ll i = 0; i < n; i++) {
        multiset<ll> ms;
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
            dp[i][j] = a[i][j] + 1;
            if(j - d - 2 >= 0) ms.erase(ms.find(dp[i][j - d - 2]));
            if(!ms.empty()) dp[i][j] += *ms.begin();
            ms.insert(dp[i][j]);
        }
    }
    
    vector<ll> pre(n, 0); pre[0] = dp[0][m - 1];
    for (ll i = 1; i < n; i++) pre[i] = pre[i - 1] + dp[i][m - 1];

    ll mn = INF;
    for (ll i = k - 1; i < n; i++) mn = min(mn, pre[i] - (i == k - 1 ? 0ll : pre[i - k]));
    cout << mn << endl;
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