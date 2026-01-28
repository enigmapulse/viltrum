#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k, q; cin >> n >> k >> q;
    vector<vector<ll>> grid(k, vector<ll> (n));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) {
            cin >> grid[j][i];
            if(i) grid[j][i] |= grid[j][i - 1];   
        }
    }
    
    while(q--) {
        ll m; cin >> m;
        ll L = 0, R = n - 1;
        while(m--) {
            ll r, c; char o; cin >> r >> o >> c;
            if(o == '>') {
                auto it = upper_bound(all(grid[r - 1]), c);
                if(it == grid[r - 1].end()) L = n + 1;
                ll idx = it - grid[r - 1].begin();
                L = max(idx, L);
            }
            else {
                auto it = lower_bound(all(grid[r - 1]), c); 
                R = min(R, (ll)distance(grid[r - 1].begin(), it) - 1LL);
            }
        }

        if(L <= R) cout << L + 1 << endl;
        else cout << -1 << endl;
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