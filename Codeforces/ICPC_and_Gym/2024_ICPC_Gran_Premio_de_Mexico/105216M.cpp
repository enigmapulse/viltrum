#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define M_PI		3.14159265358979323846
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    double l, r; cin >> l >> r;

    auto f = [&] (double x) {
        double res = 3 * (x * x * x) - 3 * (x * x * r) - 2 * (x * l * l) - (r * l * l);
        return (res >= 0);
    };

    double lo = r, hi = r + l;
    for (ll i = 0; i < 20; i++) {
        double mid = lo + (hi - lo)/2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }

    double theta = acos((lo - r)/l);
    cout << fixed << setprecision(10) << M_PI - theta << endl;
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