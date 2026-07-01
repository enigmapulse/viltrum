#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

const ll MAXN = 1000005;
ll spf[MAXN];
vector<ll> primes;

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

void fillp() {
    primes.reserve(MAXN);
    for (ll i = 2; i < MAXN; i++) {
        if(spf[i] == i) primes.push_back(i);   
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
    bool chk = false;
    for(auto p : primes) {
        if (p * p > n) break;
        ll cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        if(cnt >= 2) {chk = true; break;}
    }
    if(chk) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; sieve(); fillp();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}