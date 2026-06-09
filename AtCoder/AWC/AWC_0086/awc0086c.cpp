#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> b(m, 0); inarr(b, m);
    sort(all(b));
    vector<ll> pre(m, 0);
    while (q--) {
        ll l, r; cin >> l >> r;
        auto it = lower_bound(all(b), l);
        auto ut = upper_bound(all(b), r);
        if(it != b.end()) pre[it - b.begin()] ^= 1;
        if(ut != b.end()) pre[ut - b.begin()] ^= 1;
    }
    for (ll i = 1; i < m; i++) pre[i] ^= pre[i - 1];
    ll cnt = accumulate(all(pre), 0ll);
    cout << cnt << endl;
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