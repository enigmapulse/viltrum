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
    sort(all(a));
    ll best = 1e15;
    for (ll i = 0; i < n; i++) {
        auto it = lower_bound(all(a), a[i]);
        ll left = it - a.begin();
        auto ut = upper_bound(all(a), a[i]);
        ll right = ut - a.begin(); right = n - right;
        best = min(best, max(left, right));
    }
    cout << best << endl;
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