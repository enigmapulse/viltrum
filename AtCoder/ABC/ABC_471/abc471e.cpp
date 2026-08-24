#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = false;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modinv(ll num) {
    return binpow(num, MOD - 2);
}

ll nck(ll n, ll k) {
    if(k == 0) return 1;
    if(k == -1) return 0;
    ll res = 1;
    ll big = k, small = n - k;
    if(big < small) swap(big, small);
    for (ll i = n; i > big; i--) res = (res * i) % MOD;
    for (ll i = 2; i <= small; i++) res = (res * modinv(i)) % MOD;
    return res;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    ll sos = 0, sm = 0;
    for (ll i = 0; i < n; i++) {
        ll curr = (a[i] * a[i]) % MOD;
        sos = (sos + curr) % MOD;
        sm = (sm + a[i]) % MOD;
    }
    
    ll pairs = (sm * sm) % MOD;
    pairs = (pairs - sos + MOD) % MOD;

    // cerr << sos << endl;
    // cerr << sm << endl;
    // cerr << pairs << endl;

    ll ans = (sos * nck(n - 1, k - 1)) % MOD;
    ans = (ans + (pairs * nck(n - 2, k - 2)) % MOD) % MOD;
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