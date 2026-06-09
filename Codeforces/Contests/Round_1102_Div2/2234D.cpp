#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll k, n; cin >> k >> n; n = (1ll << n) + 1;
    vector<string> a(n + 1, string(k, '0'));
    cin >> a[1] >> a[n];
    auto f = [&] (auto&& f, ll l, ll r)->void {
        if (r - l <= 1) return;
        ll mid = (l + r) / 2;
        for (ll i = 0; i < k; i++) {
            a[mid][i] = (a[l][i] == a[r][i]) ? '0' : '1';
        }
        f(f, l, mid);
        f(f, mid, r);
    };
    f(f, 1, n);
    
    ll ans = 0;
    vector<ll> cnt(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        for (ll bit = 0; bit < k; bit++) cnt[i] += a[i][bit] - '0';
        ans += (k - cnt[i]) * cnt[i];
    }
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