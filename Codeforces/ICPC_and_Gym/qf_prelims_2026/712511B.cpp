#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n = 10;
    vector<double> dp(n + 1, 0);
    double curr = 0;

    for (ll i = 9; i >= 2; i--) {
        dp[i] = (10.00 - i)/2 + curr / (11.0 - i);
        curr += dp[i];
    }
    for (ll i = 2; i <= 10; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
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