#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll f(ll x) {
    return (63 - __builtin_clzll(x));
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);

    vector<ll> ops_cnt(n, 0), oppose(n, 1), adv(n, 0);
    for (ll i = 0; i < n; i++) {
        ops_cnt[i] = f(a[i]);
        if(i != 0) ops_cnt[i] += ops_cnt[i - 1];
        if((a[i] & (a[i] - 1)) == 0) oppose[i] = 0;
        if(i != 0) oppose[i] += oppose[i - 1];
        if(a[i] == (1ll << f(a[i])) + 1) adv[i] = 1;
        if(i != 0) adv[i] += adv[i - 1];
    }
    
    while (q--) {
        ll l, r; cin >> l >> r;
        ll ans = ops_cnt[r - 1] - (l > 1 ? ops_cnt[l - 2] : 0);
        ans += oppose[r - 1] - (l > 1 ? oppose[l - 2] : 0);
        ll val = adv[r - 1] - (l > 1 ? adv[l - 2] : 0);
        ans -= (val + 1) / 2;
        cout << ans << endl;
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