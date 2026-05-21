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
    vector<ll> mn(n, 0), mx(n, 0);
    mn[0] = a[0]; mx[0] = abs(a[0]);

    for (ll i = 1; i < n; i++) {
        mn[i] = mn[i - 1] + a[i];
        mx[i] = max(abs(mx[i - 1] + a[i]), abs(mn[i - 1] + a[i]));
    }

    vector<ll> dp1(n, 0), dp2(n, 0); dp1[0] = dp2[0] = 1;
    for (ll i = 0; i < n - 1; i++) {
        ll cnt = 0;
        cnt += (mn[i] + a[i + 1] == mx[i + 1]);
        cnt += (abs(mn[i] + a[i + 1]) == mx[i + 1]);
        dp1[i + 1] = (dp1[i + 1] + dp2[i] * cnt) % MOD;

        cnt = 0;
        cnt += (mn[i] + a[i + 1] == mn[i + 1]);
        cnt += (abs(mn[i] + a[i + 1]) == mn[i + 1]);
        dp2[i + 1] = (dp2[i + 1] + dp2[i] * cnt) % MOD;

        if(mn[i] != mx[i]) {
            cnt = 0;
            cnt += (mx[i] + a[i + 1] == mx[i + 1]);
            cnt += (abs(mx[i] + a[i + 1]) == mx[i + 1]);
            dp1[i + 1] = (dp1[i + 1] + dp1[i] * cnt) % MOD;
        

            cnt = 0;
            cnt += (mx[i] + a[i + 1] == mn[i + 1]);
            cnt += (abs(mx[i] + a[i + 1]) == mn[i + 1]);
            dp2[i + 1] = (dp2[i + 1] + dp1[i] * cnt) % MOD;
        }
    }
    cout << dp1[n - 1] % MOD << endl;
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