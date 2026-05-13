#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e15;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, w; cin >> n >> w;
    vector<ll> wt(n + 1), val(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    ll bestv = 0;
    vector<ll> dp(1e5 + 1,INF); dp[0] = 0;
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1e5; j >= 0; j--) {
            if(val[i] > j) continue;
            dp[j] = min(dp[j], dp[j - val[i]] + wt[i]);
            if(dp[j] <= w) bestv = max(bestv, j);
        }
    }
    
    cout << bestv << endl;
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