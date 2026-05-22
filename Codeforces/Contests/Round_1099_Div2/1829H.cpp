#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    vector<ll> ct(64, 0);
    for (ll mask = 0; mask < 64; mask++) {
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if((a[i] & mask) == mask) {
                cnt++;
            }
        }
        ct[mask] = (power(2, cnt) - 1 + MOD) % MOD;
    }

    for (ll mask = 63; mask >= 0; mask--) {
        for (ll bmask = 0; bmask < 64; bmask++) {
            if((bmask & mask) != mask || bmask == mask) continue;
            ct[mask] = (ct[mask] - ct[bmask] + MOD) % MOD;
        }
    }
    
    ll sm = 0;
    for (ll mask = 0; mask < 64; mask++) {
        if(__builtin_popcount(mask) == k) sm = (sm + ct[mask]) % MOD;
    }
    cout << sm << endl;
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