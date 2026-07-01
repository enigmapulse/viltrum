#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k); 
    inarr(a, n); inarr(b, m); inarr(c, k);

    ll diff = 0, cnt = 0; ll l, r;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i + 1] - a[i] > diff) {
            diff = a[i + 1] - a[i];
            l = a[i], r = a[i + 1];
            cnt = 1;
        }
        else if(a[i + 1] - a[i] == diff) cnt++;
    }
    ll mx = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i + 1] - a[i] != diff) mx = max(mx, a[i + 1] - a[i]);
    }
    
    
    if(cnt > 1) {
        cout << diff << endl;
        return;
    }

    for (ll i = 0; i < k; i++) c[i] = 2 * c[i];
    sort(all(c)); ll mn = diff;
    for (ll i = 0; i < m; i++) {
        ll target = l + r - 2 * b[i];
        auto it = lower_bound(all(c), target);
        if(it != c.end() && (*it) / 2 + b[i] <= r) mn = min(mn, max({(*it) / 2 + b[i] - l, r - (*it) / 2 - b[i], mx}));
        if(it != c.begin()) {
            auto ut = prev(it);
            if((*ut) / 2 + b[i] < l) continue;
            mn = min(mn, max({(*ut) / 2 + b[i] - l, r - (*ut) / 2 - b[i], mx}));
        }
    }
    cout << mn << endl;
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