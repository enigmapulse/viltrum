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
        ll n; cin >> n;
        for()
    }
}