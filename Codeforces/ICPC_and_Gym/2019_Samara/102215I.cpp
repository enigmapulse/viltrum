#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

ll f (ll side, ll brush) {
    if(brush >= side) return 0;
    else return 3 * (side - brush) + max(side - 2 * brush, 0LL) + (side - 2 * brush > 0 ? min(brush, side - 2* brush) : 0) + f(side - 2 * brush, brush);
}

bool multipleTests = false;

void solve() {
    ll a, b; cin >> a >> b;
    cout << f(a, b) << endl;
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