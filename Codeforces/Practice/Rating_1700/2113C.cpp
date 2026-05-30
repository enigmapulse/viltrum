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
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];
    
    ll cnt = 0;
    vector<vector<ll>> pref(n, vector<ll> (m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == 'g') {pref[i][j] = 1; cnt++;}
            if(j > 0) pref[i][j] += pref[i][j - 1];
        }
        if(i > 0) for (ll j = 0; j < m; j++) pref[i][j] += pref[i - 1][j];
    }

    auto f = [&] (ll x, ll y) {
        // x, y is the middle point of the explostion
        ll tl_x = x - k, tl_y = y - k;
        ll tr_x = min(x + k - 1, n - 1), tr_y = y - k;
        ll bl_x = x - k, bl_y = min(y + k - 1, m - 1);
        ll br_x = min(x + k - 1, n - 1), br_y = min(y + k - 1, m - 1);
        ll val1 = ((tl_x >= 0 && tl_y >= 0) ? pref[tl_x][tl_y] : 0ll);
        ll val2 = ((tr_x >= 0 && tr_y >= 0) ? pref[tr_x][tr_y] : 0ll);
        ll val3 = ((bl_x >= 0 && bl_y >= 0) ? pref[bl_x][bl_y] : 0ll);
        ll val4 = ((br_x >= 0 && br_y >= 0) ? pref[br_x][bl_y] : 0ll);
        return (val4 - val3 - val2 + val1);
    };

    ll mn = 1e15;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == '.') mn = min(mn, f(i, j));
        }
    }
    cout << cnt - mn << endl;
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