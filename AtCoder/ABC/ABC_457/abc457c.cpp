#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<vector<ll>> a(n);
    for (ll i = 0; i < n; i++) {
        ll sz; cin >> sz;
        a[i].reserve(sz);
        for (ll j = 0; j < sz; j++) {
            ll y; cin >> y;
            a[i].push_back(y);
        }
    }

    vector<ll> c(n); inarr(c, n); k--;

    ll idx = -1;
    for (ll i = 0; i < n; i++) {
        if(k >= c[i] * a[i].size()) k -= c[i] * a[i].size();
        else {idx = i; break;}
    }

    k = k % a[idx].size();
    cout << a[idx][k] << endl;
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