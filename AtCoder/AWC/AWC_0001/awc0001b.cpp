#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n); inarr(a, n);
    ll mx = -1, idx = -1;
    for (ll i = 0; i < n; i++) {
        if(a[i] >= l && a[i] <= r && a[i] > mx) {
            mx = a[i];
            idx = i;
        }
    }
    if(idx == -1) cout << -1 << endl;
    else cout << idx + 1 << endl;
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