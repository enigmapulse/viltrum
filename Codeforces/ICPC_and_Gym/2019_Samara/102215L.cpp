#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll x1, y1, r1;
    cin >> x1 >> y1 >> r1;

    ll x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    long double dx = (long double)x2 - x1;
    long double dy = (long double)y2 - y1;

    long double dist = hypotl(dx, dy);

    long double radius = (r1 + r2 - dist) / 2.0;

    long double m1 = dist - r1 + r2;
    long double m2 = dist - r2 + r1;

    long double nx = (m2 * x2 + m1 * x1) / (2.0 * dist);
    long double ny = (m2 * y2 + m1 * y1) / (2.0 * dist);

    cout << fixed << setprecision(12);
    cout << nx << " " << ny << " " << radius;
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