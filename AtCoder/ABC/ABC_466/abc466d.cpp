#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    
    vector<pll> ops(m);
    for (ll i = 0; i < m; i++) {
        cin >> ops[i].first >> ops[i].second;
    }
    
    set<ll> r, c; ll cnt = 0;
    for (ll op = m - 1; op >= 0; op--) {
        auto [row, col] = ops[op];
        bool chk1 = r.insert(row).second ;
        bool chk2 = c.insert(col).second;
        if(chk1 && chk2) cnt++; 
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