#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll l, r; cin >> l >> r;
    ll ops = 0, mx = 0;

    for (ll i = 31; i >= 0; i--) {
        bool pos1 = ((l >> i) & 1);
        bool pos2 = ((r >> i) & 1);
        ll mask = (1ll << (i + 1)) - 1;
        l = (mask & l);
        r = (mask & r);
        if(pos1 != pos2) {
            mx += (1ll << i);
        }
        else if(pos1 == 0) {
            ll inc = (1ll << i) - r;
            if(inc <= l) {
                r += inc; l -= inc;
                mx += (1ll << i);
                ops += inc;
            }
        }
        else {
            ll dec = l - (1ll << i) + 1;
            ll lim = (1ll << (i + 1)) - 1;
            if(r + dec <= lim) {
                r += dec; l -= dec;
                mx += (1ll << i);
                ops += dec;
            }
        }
    }
    cout << mx << " " << ops << endl;
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