#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        a.push_back({u, v});
    }
    
    double curr = a[n - 1].first;

    for (ll i = n - 2; i >= 0; i--) {
        curr = max(curr, curr * (1.0 - a[i].second / 100.0) + a[i].first);
    }
    
    cout << fixed << setprecision(10) << curr << endl;
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