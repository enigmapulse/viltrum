#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1, 0); inarr(a, n);

    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<ll> b(a.begin() + 1, a.end());
    sort(all(b));
    ll med = b[n/2];
    
    vector<ll> dp(n + 1, -1e9);
    dp[0] = 0;

    for (ll i = 1; i <= n; i++) {
        ll less = 0, more = 0, match = 0;
        for (ll j = 1; j <= i; j++) {
            if(a[i - j + 1] == med) match++;
            else if (a[i - j + 1] < med) less++;
            else more++;

            if((j & 1) && (less < match + more && more < match + less)) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }
    
    cout << dp[n] << endl;
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