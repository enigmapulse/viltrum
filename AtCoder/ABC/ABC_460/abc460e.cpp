#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

ull power(ull base, ull expo) {
    ull cur = 1;
    for (ull i = 0; i < expo; i++) {
        cur = (cur * base);
    }
    return cur;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll ans = 0;
    for (ll d = 1; d <= 19; d++) {
        if(power(10, d - 1) > (ull)n) break;
        ll cy = (min(power(10, d) - 1, (ull)n) - min(power(10, d - 1), (ull)n) + 1) % MOD;
        ll g = gcd((power(10, d) - 1) % m, (ull)m); 
        ll cx = (n / (m / g)) % MOD;
        ans = (ans + (cx * cy) % MOD) % MOD;
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