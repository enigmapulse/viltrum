#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;
    ll d = 0, mx = -2e18; 
    
    for (ll i = 0; i < n; i++) {
        ll a, b, c; cin >> a >> b >> c;
        d += a * (b - 1);
        ll ef = (a * b) - c;
        mx = max(mx, ef);
    }
    
    if (d >= x) {
        cout << 0 << endl;
        return;
    }
    if (mx <= 0) {
        cout << -1 << endl;
        return;
    }
    
    ll rem = x - d;
    ll bc = (rem + mx - 1) / mx;
    
    cout << bc << endl;
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