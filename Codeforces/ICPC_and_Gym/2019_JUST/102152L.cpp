#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

bool multipleTests = false;

void solve() {
    ll n, m, h, w; cin >> n >> m >> h >> w;
    vector<vector<ll>> a(n, vector<ll> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ordered_set s;
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            s.insert(a[i][j]);
        }
    }
    
    ll mn = 1e5;
    
    
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