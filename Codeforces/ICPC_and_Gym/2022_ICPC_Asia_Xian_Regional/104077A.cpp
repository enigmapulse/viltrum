#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    ll q; cin >> q;
    vector<ll> a(n + 1); iota(all(a), 0);
    while(q--) {
        ll ops; cin >> ops;
        if(ops == 2) {
            ll x; cin >> x;
            cout << a[x] << endl;
        }
        else {
            ll u, v; cin >> u >> v;
            swap(a[u], a[u + 1]);
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