#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e15;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> pre(n, 0); 
    for (ll i = 0; i < n; i++) {
        if(i == 0) pre[i] = a[i];
        else pre[i] = a[i] + pre[i - 1];
    }
    

    vector<vector<ll>> dp(n, vector<ll> (n, INF));
    for (ll len = 0; len < n; len++) {
        for (ll start = 0; start < n - len; start++) {
            ll end = start + len;
            if(start == end) {
                dp[start][end] = 0;
                continue;
            }
            for (ll k = start; k < end; k++) {
                dp[start][end] = min(dp[start][k] + dp[k + 1][end], dp[start][end]);
            }
            dp[start][end] += pre[end] - (start > 0 ? pre[start - 1] : 0);
        }
    }
    
    cout << dp[0][n - 1] << endl;
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