#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> l(m), r(m);
    for (ll i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
    }
    ll q; cin >> q;
    vector<ll> c(q); inarr(c, q);

    auto chk = [&] (ll x) {
        // we need to check if the answer is <= x
        vector<ll> tmp(n + 1, 0);
        for (ll i = 0; i < x; i++) tmp[c[i]] = 1;
        // count 1s - 0s
        for (ll i = 1; i <= n; i++) tmp[i] = tmp[i - 1] + (tmp[i] == 1 ? 1 : -1);
        bool ret = false;
        for (ll i = 0; i < m; i++) {
            ll left = (l[i] > 1 ? tmp[l[i] - 1] : 0);
            ll right = tmp[r[i]];
            ret |= (right > left);
        }
        return ret;
    };

    ll lo = 1, hi = q + 1; ll ans = -1;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) {ans = mid; hi = mid;}
        else lo = mid + 1;
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