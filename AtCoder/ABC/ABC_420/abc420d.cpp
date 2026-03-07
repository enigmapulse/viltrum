#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> grid(n, string(m, ' ')); 

    pair<ll, ll> st, end;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') st = {i, j};
            if(grid[i][j] == 'G') end = {i, j};
        }
    }

    auto chk = [&] (ll i, ll j) {
        bool res = true;
        res &= (i >= 0) && (i < n);
        res &= (j >= 0) && (j < m);
        return res;
    };

    vector<vector<vector<ll>>> dist(n, vector<vector<ll>> (m, vector<ll> (2, 1e12)));
    vector<pair<ll, ll>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    queue<pair<pair<ll, ll>, ll>> q; q.push({st, 1}); dist[st.first][st.second][1] = 0;
    while(!q.empty()) {
        ll x = q.front().first.first;
        ll y = q.front().first.second;
        ll z = q.front().second;
        q.pop();

        if(grid[x][y] == 'G') {
            cout << min(dist[x][y][0], dist[x][y][1]) << endl;
            return;
        }

        for(auto [dx, dy] : dirs) {
            ll nx = x + dx;
            ll ny = y + dy;
            ll nz = z;

            if(!chk(nx, ny)) continue;
            char ch = grid[nx][ny];
            if(ch == '?') nz = nz ^ 1;
            if(dist[nx][ny][nz] != 1e12 || (ch == 'x' && z) || (ch == 'o' && !z) || ch == '#') continue;

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({{nx, ny}, nz}); 
        }
    }

    cout << -1 << endl;
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