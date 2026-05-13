#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<pll> a;
    a.reserve(3*n);
    for (ll i = 0; i < n; i++) {
        ll u, v, w; cin >> u >> v >> w;
        a.push_back({u, i});
        a.push_back({v, i});
        a.push_back({w, i});
    }
    sort(all(a));
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