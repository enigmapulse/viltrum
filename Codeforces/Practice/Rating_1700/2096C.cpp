#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e15;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> grid(n, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) inarr(grid[i], n);
    vector<ll> row(n), col(n); inarr(row, n); inarr(col, n);

    vector<vector<ll>> dpr(n, vector<ll>(2, INF));
    dpr[0][0] = 0;
    dpr[0][1] = row[0];

    for (ll i = 1; i < n; i++) {
        for (ll p = 0; p < 2; p++) {
            if (dpr[i - 1][p] == INF) continue;
            for (ll c = 0; c < 2; c++) {
                bool ok = true;
                for (ll j = 0; j < n; j++) {
                    if (grid[i - 1][j] + p == grid[i][j] + c) ok = false;
                }
                if (ok) dpr[i][c] = min(dpr[i][c], dpr[i - 1][p] + (c ? row[i] : 0));
            }
        }
    }

    vector<vector<ll>> dpc(n, vector<ll>(2, INF));
    dpc[0][0] = 0;
    dpc[0][1] = col[0];

    for (ll j = 1; j < n; j++) {
        for (ll p = 0; p < 2; p++) {
            if (dpc[j - 1][p] == INF) continue;
            for (ll c = 0; c < 2; c++) {
                bool ok = true;
                for (ll i = 0; i < n; i++) {
                    if (grid[i][j - 1] + p == grid[i][j] + c) ok = false;
                }
                if (ok) dpc[j][c] = min(dpc[j][c], dpc[j - 1][p] + (c ? col[j] : 0));
            }
        }
    }
    
    ll ans_r = min(dpr[n - 1][0], dpr[n - 1][1]);
    ll ans_c = min(dpc[n - 1][0], dpc[n - 1][1]);

    if(ans_r == INF || ans_c == INF) cout << -1 << endl;
    else cout << ans_r + ans_c << endl;
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