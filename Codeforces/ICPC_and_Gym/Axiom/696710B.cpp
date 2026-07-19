#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll x, y, m, k; cin >> x >> y >> m >> k;
    if(gcd(x, y) != 1) {
        cout << -1 << endl;
        return;
    }
    if(x < y) swap(x, y);

    auto f = [&] (auto&& f, ll big, ll small) -> ll {
        if(big == 1 && small == 1) return 0ll;
        ll times = (big + small - 1) / small;
        times--;
        ll nbig = big - times * small;
        ll nsmall = small;
        if(nbig < nsmall) swap(nbig, nsmall);
        ll q = times / m, r = times % m;
        if (k < m) {
            times = q * k + r; 
        }
        return times + f(f, nbig, nsmall);
    };

    cout << f(f, x, y) << endl;
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