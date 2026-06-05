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
    string s; cin >> s;

    if(n < 3) {
        cout << 0 << endl;
        return;
    }

    vector<ll> dp(n, 0);
    if(s[0] == s[1] && s[1] == s[2]) dp[2] = 1;

    for (ll i = 3; i < n; i++) {
        if(s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
            dp[i] = min({dp[i - 1], dp[i - 2], dp[i - 3]}) + 1;
        } else dp[i] = dp[i - 1];
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