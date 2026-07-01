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
    ll ans = 0;
    vector<vector<ll>> end(n / 2 + 1, vector<ll> (n + 2, n + 1));
    for (ll i = 0; i < n; i++) {
        vector<bool> seen(n + 1, false);
        ll mn = n + 1, mx = 0, cnt = 0;
        for (ll j = i; j < n; j++) {
            if(seen[a[j]]) {
                if(j != i) break;
            }
            seen[a[j]] = true;
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            cnt++;
            if(cnt > n / 2) break;
            if(mx - mn + 1 == cnt) {
                if(mn - 1 >= 0 && end[cnt][mn - 1] < i) {
                    ans = max(ans, cnt);
                }
                if(mx + cnt <= n && end[cnt][mx + cnt] < i) {
                    ans = max(ans, cnt);
                }
                end[cnt][mx] = min(end[cnt][mx], j);
            }
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