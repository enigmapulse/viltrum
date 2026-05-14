#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll p, q; cin >> p >> q;

    ll val = 2 * (p + 2 * q) + 1;
    for (ll i = 1; i * i <= val; i++) {
        if(val % i != 0) continue;
        ll m = val / i, n = i;
        if((m & 1) && (n & 1)) {
            m = m / 2; n = n / 2;
            if(m == 0 || n == 0) continue;
            if(abs(m - n) <= p) {
                cout << m << " " << n << endl;
                return;
            }
        }
    }
    
    cout << -1 << endl;
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