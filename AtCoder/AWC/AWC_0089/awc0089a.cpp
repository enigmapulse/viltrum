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
    ll sm = accumulate(all(a), 0ll);

    while(q--){
        ll u; cin >> u;
        sm -= a[u - 1];
        a[u - 1] = 0;
        cout << sm << endl;
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