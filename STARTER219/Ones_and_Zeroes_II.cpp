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
    string s; cin >> s;

    vector<ll> p;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '1') p.push_back(i);
    }

    ll cnt = p.size();
    ll mx = min(n, 2 * cnt);
    
    ll ans = 0;
    for (ll i = 0; i < cnt; i++) {
        if (p[i] > 2 * i) {
            ans += (p[i] - 2 * i);
        }
    }

    cout << mx << " " << ans << endl;
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