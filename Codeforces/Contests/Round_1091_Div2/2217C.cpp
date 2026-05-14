#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, a, b; cin >> n >> m >> a >> b;
    bool chk1 = (gcd(n, a) == 1);
    bool chk2 = (gcd(m, b) == 1);
    bool chk3 = (gcd(n, m) <= 2);
    bool chk = chk1 & chk2 & chk3;
    if(chk) cout << "YES" << endl;
    else cout << "NO" << endl;
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