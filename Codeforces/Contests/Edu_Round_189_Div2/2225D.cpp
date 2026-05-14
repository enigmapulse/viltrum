#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;
    
    // 1 is coming at 4n
    // 0 4n + 3
    x--; 
    ll r = x % 4, q = x / 4;
    ll l0 = 1 + q + (r == 3 ? 1 : 0);
    ll l1 = q + (r >= 1 ? 1 : 0);

    r = n % 4, q = n / 4;
    ll r0 = 1 + q + (r == 3 ? 1 : 0);
    ll r1 = q + (r >= 1 ? 1 : 0);

    r0 %= MOD;
    l0 %= MOD;
    r1 %= MOD;
    l1 %= MOD;

    r1 = (r1 - l1 + MOD) % MOD;
    r0 = (r0 - l0 + MOD) % MOD;

    cout << ((r0 * l0) % MOD+ (r1 * l1) % MOD) % MOD << endl;
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