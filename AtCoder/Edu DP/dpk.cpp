#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    vector<bool> dp(k + 1, false);
    for (ll i = 0; i <= k; i++) {
        for (ll j = 0; j < n; j++) {
            if(i - a[j] >= 0) dp[i] = dp[i] | (!dp[i - a[j]]);
        }
    }
    
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
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