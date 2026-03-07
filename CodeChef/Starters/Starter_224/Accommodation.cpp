#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll b, g, x, y, n; cin >> b >> g >> x >> y >> n;
    if(x + y > n) {
        cout << -1 << endl;
        return;
    }

    ll val = (b + g + n - 1) / n;
    if(b >= val * x && g >= val * y) cout << val << endl;
    else cout << -1 << endl;
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