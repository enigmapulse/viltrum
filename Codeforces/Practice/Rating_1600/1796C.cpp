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
    ll l, r; cin >> l >> r;

    ll curr = l; ll sz = 0;
    while(curr <= r) {
        curr = curr * 2;
        sz++;
    }

    ll ans = 0;
    ll mul1 = (1 << (sz - 1)), mul2 = (1 << (sz - 2)) * 3;
    ans = (ans + max(0LL, r / mul1 - l + 1)) % MOD;
    ans = (ans + ((sz - 1) * max(0LL, r / mul2 - l + 1)) % MOD) % MOD;

    cout << sz << " " << ans << endl;
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