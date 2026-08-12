#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;

    auto chk = [&] (ll x, ll y) {
        bool chk1 = (x >= 1) && (x <= 10);
        bool chk2 = (y >= 1) && (y <= 10);
        return (chk1 && chk2);
    };

    vector<vector<ll>> grid(11, vector<ll> (11, 0));
    for (ll i = 0; i < n; i++) {
        ll d, l, r, c; cin >> d >> l >> r >> c;
        if(d == 0) {
            for (ll i = 0; i < l; i++) {
                ll cx = r, cy = c + i;
                if(!chk(cx, cy)) {
                    cout << "N" << endl;
                    return;
                }
                grid[cx][cy]++;
            }
        }
        else {
            for (ll i = 0; i < l; i++) {
                ll cx = r + i, cy = c;
                if(!chk(cx, cy)) {
                    cout << "N" << endl;
                    return;
                }
                grid[cx][cy]++;
            }
        }
    }
    
    for (ll i = 1; i <= 10; i++) {
        for (ll j = 1; j <= 10; j++) {
            if(grid[i][j] > 1) {
                cout << "N" << endl;
                return;
            }
        }
    }
    cout << "Y" << endl;
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