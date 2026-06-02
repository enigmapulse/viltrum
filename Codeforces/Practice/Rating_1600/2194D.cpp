#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    ll tot = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) tot++;
        }
    }

    if(tot == 0) {
        cout << 0 << endl;
        for (ll i = 0; i < n; i++) cout << "D";
        for (ll j = 0; j < m; j++) cout << "R";
        cout << endl;
        return;
    }

    ll cnt = 0, idx = -1, down = 0;
    for (ll j = 0; j < m; j++) {
        for (ll i = 0; i < n; i++) cnt += grid[i][j];
        if(cnt > tot / 2) {
            idx = j;
            for (ll i = 0; i < n; i++) {
                cnt -= grid[i][j]; down++;
                if(cnt == tot / 2)  break;
            }
            break;
        }
    }
    
    string path = "";
    for (ll i = 0; i < idx; i++) path += "R";
    for (ll i = 0; i < down; i++) path += "D";
    path += "R";
    for (ll i = down; i < n; i++) path += "D";
    for (ll i = idx + 1; i < m; i++) path += "R";
    cout << (tot / 2) * (tot - tot / 2) << endl;
    cout << path << endl;
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