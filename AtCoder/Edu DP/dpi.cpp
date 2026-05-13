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
    vector<double> p(n); inarr(p, n);

    vector<vector<double>> mp(n, vector<double>(2*n+1, -1));
    function<double(ll, ll)> f = [&] (ll idx, ll delta) {
        if (idx == -1) return double(delta == 0);
        if (mp[idx][delta + n] != -1) return mp[idx][delta + n];
        return mp[idx][delta + n] = (p[idx] * f(idx - 1, delta - 1) + (1 - p[idx]) * f(idx - 1, delta + 1));
    };

    double ans = 0;
    for (ll delta = 1; delta <= n; delta++) {
        ans += f(n - 1, delta);
    }
    cout << fixed << setprecision(10) << ans << endl;
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