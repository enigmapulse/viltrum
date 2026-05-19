#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define f first
#define s second
#define pb push_back

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;

    vector<pll> pts(n);
    vector<pll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> pts[i].f >> pts[i].s;
        x[i] = {pts[i].f, i}; 
        y[i] = {pts[i].s, i};
    }
    
    vector<ll> mark(n);
    sort(all(x)); sort(all(y));
    for (ll i = 0; i < n; i++) {
        auto [abs, id1] = x[i];
        if(i >= n / 2) mark[id1] += 1;
        auto [ord, id2] = y[i];
        if(i >= n / 2) mark[id2] += 2;
    }
    

    vector<vector<ll>> div_pts(4);
    for (ll i = 0; i < n; i++) {
        div_pts[mark[i]].push_back(i + 1);
    }
    
    for (ll i = 0; i < div_pts[0].size(); i++) {
        cout << div_pts[0][i] << " " << div_pts[3][i] << endl; 
    }
    for (ll i = 0; i < div_pts[1].size(); i++) {
        cout << div_pts[1][i] << " " << div_pts[2][i] << endl; 
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