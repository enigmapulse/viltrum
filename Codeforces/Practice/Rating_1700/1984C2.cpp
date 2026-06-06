#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
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

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    vector<ll> mn(n, 0), mx(n, 0);
    mn[0] = a[0]; mx[0] = abs(a[0]);

    for (ll i = 1; i < n; i++) {
        mn[i] = mn[i - 1] + a[i];
        mx[i] = max(abs(mx[i - 1] + a[i]), abs(mn[i - 1] + a[i]));
    }

    ll curr1 = 1, curr2 = 1;
    for (ll i = 1; i < n; i++) {
        ll temp1 = 0, temp2 = 0;
        if(mx[i - 1] + a[i] == mx[i]) temp1 = (temp1 + curr1) % MOD;
        if(abs(mx[i - 1] + a[i]) == mx[i]) temp1 = (temp1 + curr1) % MOD;
        if(mx[i - 1] + a[i] == mn[i]) temp2 = (temp2 + curr1) % MOD;
        if(abs(mx[i - 1] + a[i]) == mn[i]) temp2 = (temp2 + curr1) % MOD;

        if(mn[i - 1] + a[i] == mx[i]) temp1 = (temp1 + curr2) % MOD;
        if(abs(mn[i - 1] + a[i]) == mx[i]) temp1 = (temp1 + curr2) % MOD;
        if(mn[i - 1] + a[i] == mn[i]) temp2 = (temp2 + curr2) % MOD;
        if(abs(mn[i - 1] + a[i]) == mn[i]) temp2 = (temp2 + curr2) % MOD;

        if(mx[i] == mn[i] && i != n - 1) {
            temp1 = (temp1 * modinv(2)) % MOD;
            temp2 = (temp2 * modinv(2)) % MOD;
        }
        curr1 = temp1, curr2 = temp2;
    }
    cout << curr1 << endl;
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