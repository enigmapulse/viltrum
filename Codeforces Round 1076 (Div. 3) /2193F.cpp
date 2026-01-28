#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, sx, sy, ex, ey; cin >> n >> sx >> sy >> ex >> ey;
    vector<ll> x(n), y(n); inarr(x, n); inarr(y, n);
    vector<pair<ll, ll>> p(n);
    for (ll i = 0; i < n; i++) p[i] = {x[i], y[i]};
    sort(all(p));

    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ans += (p[i + 1].first - p[i].first);
    }
    ans += (p[0].first - sx) + (ex - p[n - 1].first);

    ll idx = 0; vector<pair<ll, ll>> lines;
    while(idx < n) {
        ll cx = p[idx].first;
        ll mx = 0, mn = 1e12;
        while(idx < n && p[idx].first == cx) {
            mx = max(mx, p[idx].second);
            mn = min(mn, p[idx].second);
            idx++;
        }
        lines.push_back({mx, mn});
    }

    for(auto [a, b] : lines) ans += (a - b);
    ll dp1 = 0, dp2 = 0; 
    ll pmn = sy, pmx = sy;
    for(auto [cmx, cmn] : lines) {
        ll newd = min(dp1 + abs(pmn - cmx), dp2 + abs(pmx - cmx));
        ll newd2 = min(dp1 + abs(pmn - cmn), dp2 + abs(pmx - cmn));
        dp1 = newd; dp2 = newd2; pmn = cmn; pmx = cmx;
    }
    ans += min(dp1 + abs(pmn - ey), dp2 + abs(pmx - ey));
    
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