#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

struct BIT {
    ll n;
    vector<ll> bit;

    BIT(ll n) {
        this -> n = n;
        bit.assign(n + 1, 0);
    }

    void update(ll idx, ll delta) {
        for(; idx <= n; idx += idx & -idx) bit[idx] = max(delta, bit[idx]);
    }

    ll query(ll idx) {
        ll mx = 0;
        for(; idx >= 1; idx -= idx & -idx) mx = max(mx, bit[idx]);
        return mx;
    }
};

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> h(n), a(n); inarr(h, n); inarr(a, n);

    vector<ll> dp(n + 1, 0);
    BIT tree(n);

    for (ll i = 0; i < n; i++) {
        ll q = tree.query(h[i] - 1);
        dp[h[i]] = q + a[i];
        tree.update(h[i], dp[h[i]]);
    }

    cout << *max_element(all(dp)) << endl;
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