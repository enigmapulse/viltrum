#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1); inarr(a, n);

    vector<ll> pre(n + 1, 0); 
    for (ll i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    
    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll x; cin >> x;
            pre[x] += (a[x + 1] - a[x]);
            swap(a[x], a[x + 1]);
        }
        else {
            ll l, r; cin >> l >> r;
            cout << pre[r] - pre[l - 1] << endl;
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