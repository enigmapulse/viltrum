#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

bool multipleTests = true;

void solve() {
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    ll ans = 0; ll pow = 0;
    while(true) {
        ll val = binpow(k, pow); pow++;
        ll cnt = max(0LL, min(r2 / val, r1) - max(l1, l2 / val) + 1);
        if(cnt == 0) break;
        ans += cnt;
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