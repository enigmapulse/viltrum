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
    vector<vector<ll>> num(n, vector<ll> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cin >> num[i][j];
    }
    
    vector<string> grid(n); inarr(grid, n);
    vector<vector<ll>> pre(n, vector<ll> (m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) pre[i][j] = (grid[i][j] - '0');
        for (ll j = 1; j < m; j++) pre[i][j] += pre[i][j - 1];
        for (ll j = 0; j < m; j++) if(i != 0) pre[i][j] += pre[i - 1][j];
    }

    auto f = [&] (ll i, ll j) {
        ll val1 = ((i > 0 && j > 0) ? pre[i - 1][j - 1] : 0);
        ll val2 = ((i > 0) ? pre[i - 1][j + k - 1] : 0ll);
        ll val3 = ((j > 0) ? pre[i + k - 1][j - 1]: 0ll);
        ll val4 = pre[i + k - 1][j + k - 1];
        return (val4 - val3 - val2 + val1);
    };
    
    ll g = 0;
    for (ll i = 0; i < n - k + 1; i++) {
        for (ll j = 0; j < m - k + 1; j++) {
            g = gcd(g, abs(2 * f(i, j) - k * k));
        }
    }
    
    ll diff = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == '1') diff += num[i][j];
            else diff -= num[i][j];
        }
    }
    if(g == 0) {
        if(diff == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    
    if(((diff % g) + g) % g == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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