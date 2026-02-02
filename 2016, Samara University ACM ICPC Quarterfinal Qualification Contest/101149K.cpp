#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double m = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    double n = 0.916297857297023;
    cout << setprecision(9) << fixed << m * n << endl;
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