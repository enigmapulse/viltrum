#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll MAXN = 1e6 + 2;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> range(MAXN, 0);
    for (ll i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        if(r - d > 0 && r - d >= l) {
            range[l]++;
            range[r - d + 1]--;
        }
    }
    for (ll i = 1; i < MAXN; i++) range[i] += range[i - 1];
    auto f = [&] (ll x) {
        return (x * (x - 1)) / 2;
    };

    ll ans = 0;
    for (ll i = 1; i < MAXN; i++) {
        if(range[i] > 1) ans += f(range[i]);
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