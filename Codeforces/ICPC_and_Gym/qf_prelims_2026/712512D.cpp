#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MAXN = 1e6 + 5;

using namespace std;

bool multipleTests = true;

ll dp[MAXN] = {};

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll sm = 0; sm <= 3 * n; sm++) {
        ans += sm * sm;
        
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