#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    if(abs(n - m) > k || max(n, m) < k) {
        cout << -1 << endl;
        return;
    }
    bool ones = false;
    if(n < m) ones = true;
    string ans;
    if(ones) {
        ans = string(k, '1');
        m -= k;
        ll pairs = min(n, m);
        for (ll i = 0; i < pairs; i++) {
            ans += "01"; n--; m--;
        }
        if(n) ans += string(n, '0');
        else ans += string(m, '1');
    }
    else {
        ans = string(k, '0');
        n -= k;
        ll pairs = min(n, m);
        for (ll i = 0; i < pairs; i++) {
            ans += "10"; n--; m--;
        }
        if(n) ans += string(n, '0');
        else ans += string(m, '1');
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