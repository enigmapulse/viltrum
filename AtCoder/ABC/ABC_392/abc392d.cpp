#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<map<ll, double>> a(n);
    for (ll i = 0; i < n; i++) {
        ll sz; cin >> sz;
        for (ll j = 0; j < sz; j++) {
            ll x; cin >> x;
            a[i][x]++;
        }
        for(auto [x, val] : a[i]) {
            a[i][x] = val / sz;
        }
    }

    double ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            double curr = 0;
            for(auto [x, val] : a[j]) {
                curr += val * a[i][x];
            }
            ans = max(ans, curr);
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
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