#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

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

vector<ll> primes;
void build() {
    for (ll i = 2; i < MAXN; i++) {
        if(spf[i] == i) primes.push_back(i);
    }
}

bool multipleTests = false;

void solve() {
    ll l, r; cin >> l >> r;

    ll cnt = 0;
    for (ll j = l; j <= r; j++) {
        if(getFactorization(j).size() == 1) cnt++;
    }
    
    for(auto p : primes) {
        ll k1 = 2, curr = p*p;
        while(curr < l) {
            curr = curr * p;
            k1++;
        } 

        ll k2 = k1;
        while(curr <= r) {
            curr = curr * p;
            k2++;
        }

        cnt += (k2 - k1);
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    sieve(); build();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}