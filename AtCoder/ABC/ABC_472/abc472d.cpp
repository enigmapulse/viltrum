#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second

using namespace std;

bool multipleTests = false;

void solve() {
    ll h, w, k; cin >> h >> w >> k;
    vector<string> grid(h); inarr(grid, h);

    set<ll> rows, cols;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if(grid[i][j] == '#') {
                rows.insert(i); 
                cols.insert(j); 
            }
        }
    }
    
    ll cnt = 0;
    queue<pair<pll, ll>> q;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            if(grid[i][j] == '#') continue;
            if(rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                q.push({{i, j}, 0ll});
                grid[i][j] = '#';
                cnt++;
            }
        }
    }

    vector<pll> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto val = [&] (ll i, ll j) {
        bool chk1 = (i >= 0 && i < h);
        bool chk2 = (j >= 0 && j < w);
        return(chk1 && chk2);
    };

    while (!q.empty()) {
        auto [pr, d] = q.front();
        auto [x, y] = pr;
        q.pop();
        for(auto [dx, dy] : dirs) {
            ll nx = x + dx;
            ll ny = y + dy;
            if (!val(nx, ny)) continue;
            if (grid[nx][ny] == '#') continue;
            if(d + 1 <= k) {
                cnt++;
                q.push({{nx, ny}, d + 1});
            }
            grid[nx][ny] = '#';
        }
    }
    cout << cnt << endl;
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