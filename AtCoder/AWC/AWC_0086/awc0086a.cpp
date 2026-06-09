#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, x, y, r; cin >> n >> x >> y >> r;
    ll tot = 0;

    auto f = [&] (ll cx, ll cy) {
        ll dist = (cx - x) * (cx - x) + (cy - y) * (cy - y);
        return (dist <= r * r);
    };

    for (ll i = 0; i < n; i++) {
        ll cx, cy, p; cin >> cx >> cy >> p;
        if(f(cx, cy)) tot += p;
    }
    cout << tot << endl;
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