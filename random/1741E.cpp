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
    vector<ll> a(n); inarr(a, n);
    vector<bool> dp(n + 1, false); dp[0] = true;
    for (ll i = 1; i <= n; i++) {
        ll j = a[i - 1];
        if(dp[i - 1] && i + j <= n) dp[i + j] = true;
        if(i - j - 1 >= 0 && dp[i - j - 1]) dp[i] = true; 
    }
    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
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