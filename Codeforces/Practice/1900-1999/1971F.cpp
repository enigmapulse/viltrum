#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll ceilroot(ll z) {
    if(z == 0) return 0;
    ll lo = 1, hi = 1e6;

    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(mid * mid >= z) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

ll floorroot(ll z) {
    if(z == 0) return 0;
    ll lo = 1, hi = 1e6;

    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(mid * mid < z) lo = mid;
        else hi = mid - 1;
    }

    return lo;
}

void solve() {
    ll r; cin >> r;

    ll ans = 0;
    for (ll x = 1; x <= r; x++) {
        // r^2 - x^2 <= y^2 < (r + 1)^2 - x^2
        ll lo = r*r - x*x; 
        ll hi = (r + 1)*(r + 1) - x*x; 
        ans += (floorroot(hi) - ceilroot(lo) + 1);
        if(lo == 0) ans -= 1;
    }
    
    cout << 4 * ans + 4 << endl;
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