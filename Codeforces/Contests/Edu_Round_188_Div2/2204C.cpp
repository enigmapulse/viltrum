#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c, m; cin >> a >> b >> c >> m;
    ll cnt1 = (m / a) * 6, cnt2 = (m / b) * 6, cnt3 = (m / c) * 6;
    
    ll l1 = lcm(a, b);
    cnt1 -= (m / l1) * 3;
    cnt2 -= (m / l1) * 3;

    ll l2 = lcm(b, c);
    cnt3 -= (m / l2) * 3;
    cnt2 -= (m / l2) * 3;

    ll l3 = lcm(a, c);
    cnt1 -= (m / l3) * 3;
    cnt3 -= (m / l3) * 3;

    ll l4 = lcm(lcm(a, b), c);
    cnt1 += 2 * (m / l4);
    cnt2 += 2 * (m / l4);
    cnt3 += 2 * (m / l4);

    cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
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