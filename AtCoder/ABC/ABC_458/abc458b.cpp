#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll h, w; cin >> h >> w;
    vector<vector<ll>> ans(h, vector<ll> (w, 0));

    auto chk = [&] (ll i, ll j) {
        return ((i >= 0) && (i < h) && (j >= 0) && (j < w));
    };

    vector<pair<ll, ll>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            for(auto [dx, dy] : dirs) {
                ll nx = i + dx, ny = j + dy;
                if(chk(nx, ny)) ans[i][j]++;
            }
        }
    }
    
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
            cout << ans[i][j] << " ";
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