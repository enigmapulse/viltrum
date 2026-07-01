#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    x = abs(x), y = abs(y);
    ll diff = abs(x - y);
    ll ans = 0;
    auto f = 
    if(x > y) {
        ans += (diff / 2) * b;
        ans += ((diff + 1)/ 2) * a;
        ans += 2 * y * min(a, b);
    }
    else {
        ans += (diff / 2) * a;
        ans += (diff + 1/ 2) * b;
        ans += 2 * y * min(a, b);
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