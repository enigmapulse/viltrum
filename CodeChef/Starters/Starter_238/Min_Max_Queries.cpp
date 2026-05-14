#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1); inarr(a, n);

    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll idx, val; cin >>idx >> val;
            a[idx] = val;
        }
        else {
            ll l, r; cin >> l >> r;
            ll m = (r - l + 1);
            if(r == l) {cout << a[l] << endl; continue;}
            if(r == l + 1) {cout << max(a[l], a[r]) << endl; continue;}
            if(m & 1) {
                cout << min(a[(l + r) / 2], max(a[(l + r) / 2 + 1], a[(l + r) / 2 - 1])) << endl;
            }
            else {
                cout << max(a[l + m/2 - 1], a[l + m/2]) << endl;
            }
        }
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