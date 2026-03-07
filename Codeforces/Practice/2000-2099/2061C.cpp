#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> v(n);
    for (ll i = 0; i < n; i++) v[i] = i - a[i];

    if(n == 1) {
        if(v[0] == 0) cout << 2 << endl;
        else cout << 1 << endl;
        return;
    }
    
    vector<ll> dp(n, 0);
    if(v[0] == 0) dp[0] = 1;
    if(v[1] == 0) dp[1] = 1;

    for (ll i = 0; i < n; i++) {
        ll req = v[i] + 1;
        if(i + 1 < n && v[i + 1] == req) dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
        if(i + 2 < n && v[i + 2] == req) dp[i + 2] = (dp[i + 2] + dp[i]) % MOD;
    }
    
    cout << (dp[n - 1] + dp[n - 2]) % MOD << endl;
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