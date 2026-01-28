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

    ll sm = 0;
    for (ll i = 0; i < n - 1; i++) {
        sm += abs(a[i] - a[i + 1]);
    }
    
    ll ans = sm;
    for (ll i = 1; i < n - 1; i++) {
        ll prev = a[i - 1];
        ll curr = a[i];
        ll next = a[i + 1];
        ll val = abs(next - prev) - abs(curr - prev) - abs(curr - next);
        ans = min(ans, sm + val);
    }

    ans = min(ans, sm - abs(a[0] - a[1]));
    ans = min(ans, sm - abs(a[n - 1] - a[n - 2]));
    
    cout << ans << endl;
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