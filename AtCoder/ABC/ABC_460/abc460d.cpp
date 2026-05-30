#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define ppl pair<pll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> ogrid(n), ngrid(n, string(m, '.')), ans(n); inarr(ogrid, n);

    vector<pll> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    auto chk = [&] (ll x, ll y) {
        bool chk1 = (x >= 0 && x < n);
        bool chk2 = (y >= 0 && y < m);
        return (chk1 && chk2);
    };

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(ogrid[i][j] == '.') {
                for(auto [dx, dy] : dirs) {
                    ll nx = i + dx, ny = j + dy;
                    if(chk(nx, ny) && ogrid[nx][ny] == '#') {
                        ngrid[i][j] = '#';
                    }
                }
            }
        }
    }
    ans = ngrid;

    queue<ppl> q;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(ngrid[i][j] == '#') q.push({{i, j}, 0});
        }
    }
    if(q.empty()) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cout << '.';
            }
            cout << endl;
        }
        return;
    }
    
    while(!q.empty()) {
        auto [pos, d] = q.front(); q.pop();
        auto [x, y] = pos;
        for(auto [dx, dy] : dirs) {
            ll nx = x + dx, ny = y + dy;
            if(chk(nx, ny) && ngrid[nx][ny] != '#') {
                ngrid[nx][ny] = '#';
                if(d & 1) ans[nx][ny] = '#';
                q.push({{nx, ny}, d + 1});
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(ans[i][j] == '.') cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
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