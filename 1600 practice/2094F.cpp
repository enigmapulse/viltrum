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

    vector<vector<ll>> grid(n, vector<ll> (m));

    // if m is a multiple of k
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll val = (i + j) % k;
            grid[i][j] = val;
        }
    }

    ll curr = 0;
    if(m % k != 0) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                grid[i][j] = curr++;
                curr = curr % k;
            }
        }
    }

    for(auto row : grid) {
        for(auto elem : row) {
            cout << elem + 1 << " ";
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