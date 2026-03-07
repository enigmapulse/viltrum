#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, d; cin >> n >> m >> d;
    vector<string> grid(n); inarr(grid, n);

    struct cell {ll x, y;};
    vector<pair<ll, ll>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    auto chk = [&] (ll x, ll y) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };

    queue<pair<cell, ll>> mq; 
    cell start, final;
    bool start_found = false, final_found = false;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == 'S') start = {i, j};
            if(grid[i][j] == 'F') final = {i, j};
            if(grid[i][j] == 'M') {
                mq.push({{i, j}, 0});
            }
        }
    }

    while(!mq.empty()) {
        auto [u, dt] = mq.front(); mq.pop();
        if (dt >= d) continue; 

        for(auto [dx, dy] : dirs) {
            ll nx = u.x + dx, ny = u.y + dy;
            if(chk(nx, ny) && grid[nx][ny] != 'M') {
                grid[nx][ny] = 'M'; 
                mq.push({{nx, ny}, dt + 1});
            }
        }
    }

    if (grid[start.x][start.y] == 'M') {
        cout << -1 << endl; 
        return;
    }

    queue<pair<cell, ll>> q; 
    q.push({start, 0}); grid[start.x][start.y] = 'M'; 

    while(!q.empty()) {
        auto [u, dt] = q.front(); q.pop();
        
        if(u.x == final.x && u.y == final.y) {
            cout << dt << endl;
            return;
        }

        for(auto [dx, dy] : dirs) {
            ll nx = u.x + dx, ny = u.y + dy;
            if(chk(nx, ny) && grid[nx][ny] != 'M') {
                grid[nx][ny] = 'M'; 
                q.push({{nx, ny}, dt + 1});
            }
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