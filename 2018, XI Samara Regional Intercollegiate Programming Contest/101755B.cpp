#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;

    vector<pair<ll, ll>> points;
    for (ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        points.push_back({u, v});
    }
    for (ll i = 0; i < n; i++) points.push_back(points[i]);

    auto area = [&] (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) -> __int128_t {
        __int128_t ans = 0;
        
        ans += (__int128_t)x1 * (y2 - y3);
        ans += (__int128_t)x2 * (y3 - y1);
        ans += (__int128_t)x3 * (y1 - y2);
        
        if (ans < 0) return -ans;
        return ans;
    };
    
    __int128_t ans = (__int128_t)8e18; 

    for (ll i = 0; i < n; i++) {
        auto [x1, y1] = points[i];
        auto [x2, y2] = points[i + 1];
        auto [x3, y3] = points[i + 2];
        
        __int128_t current_area = area(x1, y1, x2, y2, x3, y3);
        ans = min(ans, current_area);
    }
    
    cout << (ll)ans << endl;
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