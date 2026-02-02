#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;

    vector<vector<ll>> pre(1001, vector<ll> (1001, 0));
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        pre[x][y] += (x * y);
    }
    
    for (ll i = 1; i <= 1000; i++) {
        for (ll j = 1; j <= 1000; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    
    while(q--) {
        ll h1, w1, h2, w2; cin >> h1 >> w1 >> h2 >> w2;
        cout << pre[h2 - 1][w2 - 1] - pre[h1][w2 - 1] - pre[h2 - 1][w1] + pre[h1][w1] << endl;
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