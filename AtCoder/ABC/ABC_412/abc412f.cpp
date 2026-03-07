#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll MOD = 998244353;

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

ll modinv(ll num) {
    return binpow(num, MOD - 2);
}

ll frac(ll num, ll den) {
    ll curr = num % MOD;
    curr = (curr * modinv(den)) % MOD;
    return curr;
}

bool multipleTests = false;

void solve() {
    ll n, c; cin >> n >> c;
    vector<ll> a(n); inarr(a, n); a[c - 1]++;
    ll val = a[c - 1];
    sort(all(a));

    vector<ll> e(n);
    ll sm = accumulate(all(a), 0LL);
    e[n - 1] = frac(sm - 1, a[n - 1] - 1);

    vector<ll> pref(n, 0), suff(n + 1, 0);
    for (ll i = 1; i < n; i++) pref[i] = (pref[i - 1] + a[i - 1]) % MOD;

    for (ll i = n - 1; i >= 0; i--) {
        e[i] = frac(sm - 1 + suff[i + 1], sm - 1 - pref[i]);
        suff[i] = (e[i] * (a[i] % MOD)) % MOD + suff[i + 1];
        if(a[i] == val) {
            cout << e[i] << endl;
            break;
        }
    }
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