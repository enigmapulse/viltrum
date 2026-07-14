#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);
    ll x = 0, y = 0;
    ll r = 0, b = 0;
    for (ll i = 0; i < n; i++) {
        r += a[i];
        b -= a[i];
        x = max(x, -r);
        y = max(y, -b);
    }
    if(x + y <= k) cout << "Yes" << endl;
    else cout << "No" << endl;
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