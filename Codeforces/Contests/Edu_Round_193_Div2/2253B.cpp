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

    vector<ll> pre(n, 0), suff(n, 0);
    for (ll i = 1; i < n; i++) {
        pre[i] = (a[i] == a[i - 1]);
        pre[i] += pre[i - 1];
    }
    for (ll i = n - 2; i >= 0; i--) {
        suff[i] = (a[i] == a[i + 1]);
        suff[i] += suff[i + 1];
    }
    
    ll ans = pre[n - 1];
    for (ll i = 0; i < n - 1; i++) {
        swap(a[i], a[i + 1]);
        ll curr = 0;
        curr += (a[i] == a[i + 1]);
        if(i) curr += (a[i] == a[i - 1]);
        if(i != n - 2) curr += (a[i + 1] == a[i + 2]);
        swap(a[i], a[i + 1]);

        ll val = curr + (i ? pre[i - 1] : 0ll) + (i != n - 2 ? suff[i + 2] : 0ll);
        ans = min(ans, val);
    }
    cout << n - ans << endl;
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