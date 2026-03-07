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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        ll x, y, z; cin >> x >> y >> z;
        a[i] = x + y + z;
        vector<ll> v = {x, y, z};
        sort(all(v));
        b[i] = v[0] + v[1];
    }

    vector<ll> c = b;
    sort(all(b));
    for (ll i = 0; i < n; i++) {
        auto it = upper_bound(all(b), a[i] - 2);
        cout << it - b.begin() - (c[i] <= a[i] - 2) << " ";
    }
    cout << endl;
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