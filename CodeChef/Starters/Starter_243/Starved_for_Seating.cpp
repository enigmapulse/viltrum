#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    ll tot = accumulate(all(a), 0ll); tot = tot / 2;
    ll target = (k - tot) * 2;
    // find number of pairs with sum > target

    sort(all(a)); ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        ll nt = target - a[i];
        auto it = upper_bound(a.begin() + i + 1, a.end(), nt);
        cnt += a.end() - it;
    }
    cout << cnt << endl;
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