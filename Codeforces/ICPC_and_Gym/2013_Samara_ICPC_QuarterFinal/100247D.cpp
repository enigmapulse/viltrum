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
    string a, b, c; cin >> a >> b >> c;
    string ans;
    for (ll i = 0; i < n; i++) {
        char x = a[i], y = b[i], z = c[i];
        if(x != y && y != z && z != x) ans += x;
        else if(x == y && y == z) ans += x;
        else if(x == y) ans += x;
        else if(y == z) ans += y;
        else ans += z;
    }
    cout << ans << endl;
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