#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e15;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    string s, t; cin >> s >> t;

    vector<ll> dp(n, INF);
    dp[0] = (s[0] != t[0]);
    if(n == 1) {
        cout << dp[0] << endl;
        return;
    }
    dp[1] = min((s[0] != t[0]) + (s[1] != t[1]), (s[0] != s[1]) + (t[0] != t[1]));

    for (ll i = 2; i < n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + (s[i] != t[i]));
        dp[i] = min(dp[i], dp[i - 2] + (s[i] != s[i - 1]) + (t[i] != t[i - 1]));
    }
    cout << dp[n - 1] << endl;
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