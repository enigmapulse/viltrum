#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;

    auto md = [&] (ll n) {
        int mx = 0;
        string s = to_string(n);
        for(auto ch : s) mx = max(ch - '0', mx);
        return mx;
    };

    int ans = 0;
    for (ll i = a; i <= min(b, a + 30); i++) {
        for (ll j = c; j <= min(d, c + 30); j++) {
            ans = max(ans, md(i + j));
        }
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