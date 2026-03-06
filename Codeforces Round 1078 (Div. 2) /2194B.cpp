#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> a(n); inarr(a, n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
        b[i] = a[i] / x;
        b[i] = b[i] * y;
    }
    
    ll sm = accumulate(all(b), 0LL);

    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        mx = max(mx, (sm - b[i]) + a[i]);
    }
    cout << mx << endl;
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