#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);
    vector<ll> b(n); inarr(b, n);

    a[n - 1] = max(a[n - 1], b[n - 1]);
    for (ll i = n - 2; i >= 0; i--) {
        a[i] = max({a[i + 1], b[i], a[i]});
    }

    vector<ll> pre(n); pre[0] = a[0];
    for (ll i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];

    while(q--) {
        ll l, r; cin >> l >> r;
        ll prev = (l == 1 ? 0 : pre[l - 2]);
        cout << pre[r - 1] - prev << " ";
    }
    cout << endl;
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