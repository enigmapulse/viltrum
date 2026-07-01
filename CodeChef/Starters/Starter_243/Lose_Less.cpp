#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll m, n; cin >> m >> n;
    ll ans = 1e15;
    for (ll loses = 0; loses <= m; loses++) {
        for (ll tie = 0; tie <= m - loses; tie++) {
            ll win = m - loses - tie;
            if(win * 3 + tie == n) ans = min(ans, loses);
        }
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