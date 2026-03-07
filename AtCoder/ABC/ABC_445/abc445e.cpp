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

ll modinv(ll n) {
    return binpow(n, MOD - 2);
}

const ll MAXN = 10000005;
ll spf[MAXN];

void sieve() {
    spf[1] = 1LL;
    for (ll i = 2; i < MAXN; i++) spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<ll> getFactorization(ll n) {
    vector<ll> ret;
    while (n != 1) {
        ret.push_back(spf[n]);
        n /= spf[n];
    }
    return ret;
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    // for each prime I want the count of the maximum power that I can get from all the numbers
    // then over all the numbers if 

    ll lcm_tot = 1; map<ll, ll> lcm_map;
    for (ll i = 0; i < n; i++) {
        map<ll, ll> mp;
        for(auto p : getFactorization(a[i])) mp[p]++;
        for(auto [primes, cnt] : mp) {
            lcm_map[primes] = max(cnt, lcm_map[primes]);
        } 
    }

    for (auto [primes, cnt] : lcm_map) {
        if (cnt > 0) lcm_tot = (lcm_tot * binpow(primes, cnt)) % MOD;
    }
    
    map<ll, ll> mx, secmx;
    for (ll i = 0; i < n; i++) {
        map<ll, ll> mp;
        for(auto p : getFactorization(a[i])) mp[p]++;
        for(auto [primes, cnt] : mp) {
            if(cnt == lcm_map[primes]) mx[primes]++;
            if(cnt != lcm_map[primes]) secmx[primes] = max(cnt, secmx[primes]);
        }
    }
    
    for (ll i = 0; i < n; i++) {
        map<ll, ll> mp;
        for(auto p : getFactorization(a[i])) mp[p]++;
        ll ans = 1;
        for(auto [primes, cnt] : mp) {
            if(cnt == lcm_map[primes] && mx[primes] == 1) {
                ans = ((ans * modinv(binpow(primes, cnt))) % MOD * binpow(primes, secmx[primes])) % MOD;
            }
        }     
        cout << (lcm_tot * ans) % MOD << " ";     
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    sieve();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}