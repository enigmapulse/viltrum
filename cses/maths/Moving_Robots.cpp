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

    vector<vector<double>> emp(9, vector<double> (9, 0)), nw;
    nw = emp;

    vector<pair<ll, ll>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto isVal = [&] (ll x, ll y) {
        bool chk1 = (x >= 1 && x <= 8);
        bool chk2 = (y >= 1 && y <= 8);
        return (chk1 && chk2);
    };

    auto type = [&] (ll x, ll y) {
        ll cnt = 0;
        for(auto [dx, dy] : dirs) {
            cnt += isVal(x + dx, y + dy);
        }
        return cnt;
    };

    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= 8; i++) {
            for (ll j = 1; j <= 8; j++) {
                double cur = 1;
                for(auto [di, dj] : dirs) {
                    ll ni = i + di;
                    ll nj = j + dj;
                    if(isVal(ni, nj)) {
                        ll t = type(ni, nj);
                        double val = 1.000 + (t - 1) * emp[ni][nj];
                        cur = cur * val;
                        cur = cur / t;
                    }
                }
                nw[i][j] = cur;
            }
        }
        swap(nw, emp);
    }

    double ans = 0;
    for (ll i = 1; i <= 8; i++) {
        for (ll j = 1; j <= 8; j++) {
            ans += emp[i][j];
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
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