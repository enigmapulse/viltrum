#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);
    sort(all(a));

    auto f = [&] (ll x, ll y) {
        auto it = lower_bound(all(a), x); 
        ll offset = x - 1 - (it - a.begin());
        return y + offset;
    };

    auto chk = [&] (ll num) {
        auto it = upper_bound(all(a), num) - a.begin();
        return num - it;
    };

    auto finv = [&] (ll rank) {
        ll lo = 1, hi = 1e12;
        while(lo < hi) {
            ll mid = lo + (hi - lo)/2;
            if(chk(mid) >= rank) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    };

    while(q--) {
        ll x, y; cin >> x >> y;
        cout << finv(f(x, y)) << endl;
    }
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