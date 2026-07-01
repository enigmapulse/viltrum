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
    n += k; ll mx = 0;

    vector<ll> cnt(25, 0);
    for (ll bit = 0; bit < 25; bit++) {
        if((n >> bit) & 1) cnt[bit] = 1;
    }

    for (ll bit = 24; bit >= 0; bit--) {
        ll tot = 0; ll bits = 0;
        for (ll i = 0; i <= bit; i++) {tot += cnt[i]; bits += i * cnt[i];}
        if(tot <= k) mx = max(mx, bits);
        if(bit) cnt[bit - 1] += 2 * cnt[bit];
    }
    cout << mx << endl;
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