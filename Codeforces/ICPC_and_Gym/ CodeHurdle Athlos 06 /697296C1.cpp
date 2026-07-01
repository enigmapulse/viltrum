#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll x1, y1, x2, y2, x3, y3; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    auto f = [&] (ll x, ll y, ll rx, ll ry, ll cx, ll cy) {
        return (x - rx) * (cy - ry) - (cx - rx) * (y - ry);
    };

    auto chk = [&] (ll x, ll y) {
        ll a = f(x, y, x1, y1, x2, y2);
        ll b = f(x, y, x2, y2, x3, y3);
        ll c = f(x, y, x3, y3, x1, y1);
        return ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0));
    };

    ll q; cin >> q; ll cnt = 0;
    while (q--) {
        ll x, y; cin >> x >> y;
        if(chk(x, y)) cnt++;
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