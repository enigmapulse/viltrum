#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    inarr(a, n); inarr(b, n); inarr(c, n);

    vector<ll> preA(n), preB(n), suffC(n);

    preA[0] = a[0]; preB[0] = b[0];
    for (ll i = 1; i < n; i++) {
        preA[i] = preA[i - 1] + a[i];
        preB[i] = preB[i - 1] + b[i];
    }
    
    suffC[n - 1] = c[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        suffC[i] = suffC[i + 1] + c[i];
    }
    
    vector<ll> dp(n, 0);
    for (ll i = n - 2; i >= 0; i--) {
        dp[i] = max(dp[i + 1], preB[i] + suffC[i + 1]);
    }
    
    ll ans = 0;
    for (ll i = 0; i < n - 2; i++) {
        ans = max(ans, preA[i] + dp[i + 1] - preB[i]);
    }
    
    cout << ans << endl;
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