#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

vector<ll> factorial(2005, 1);

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

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> ans(n + 1, 0);

    ll sm = 0; ll full = 0;
    for (ll i = k; i <= n; i++) {
        ll tot = ((n - k + 1) * factorial[i]) % MOD;
        tot = (tot * modinv(factorial[i - k])) % MOD;
        tot = (tot * factorial[i - k]) % MOD;
        ans[i] = (tot - sm + MOD) % MOD;
        sm = tot;
        full = (full + (ans[i] * i) % MOD) % MOD; 
    }
    cout << full << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (ll i = 2; i <= 2004; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}