#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

const ll MAXN = 10000005;
ll spf[MAXN];
static vector<ll> primes;

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

void buildPrimes() {
    for (ll i = 2; i < MAXN; i++) {
        if(spf[i] == i) primes.push_back(i);
    }
}

void solve() {
    sieve(); buildPrimes();

    ll n; cin >> n;
    
    ll ans = 0;
    for(auto prime : primes) {
        if(n % prime == 0) ans = prime;
        while(n % prime == 0) n /= prime;
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