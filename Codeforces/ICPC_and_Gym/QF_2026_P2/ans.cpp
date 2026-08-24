#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;

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

ll frac(ll p, ll q) {
    if(p == 0) return 0;
    return ((p * modinv(q)) % MOD);
}

int main() {
    ll t = 1; 
    cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        ll num = (2 * (n * m) % MOD) % MOD;
        ll a = frac(num, (n + m)), b = 0;
        ll prev = a;
        ll p = n + m - 2, q = n + m - 1;
        ll cnt = 1;
        while(p != 0) {
            ll curr = (prev * frac(p, q)) % MOD;
            if(cnt & 1) b = (b + curr)%MOD;
            else a = (a + curr)%MOD;
            prev = curr;
            p--; q--;
            cnt++;
        }
        cout << a << " " << b << endl;
    }
}