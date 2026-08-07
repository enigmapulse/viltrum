#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    if(n & 1) {
        cout << "NO" << endl;
        return;
    }

    ll mx = 1e12, mn = 0;
    for (ll i = 0; i < n; i++) {
        if(i & 1) mn = max(mn, a[i]);
        else mx = min(mx, a[i]);
    }

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] < mx && a[i] > mn) cnt++;
    }
    if(cnt == mx - mn - 1) {
        cout << "NO" << endl;
        return;
    }

    if(mx - mn > 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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