#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

const ll MAXN = 1000005;
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

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp; ll totprimes = 0;
    for (ll i = 0; i < n; i++) {
        ll val = a[i];
        vector<ll> factors = getFactorization(val);
        if(factors.size() <= 2) mp[val]++;
        if(factors.size() == 1) totprimes++;
    }
    
    ll ans = 0; ll fprimes = 0;
    for(auto [val, cnt] : mp) {
        vector<ll> factors = getFactorization(val);
        
        if(factors.size() == 2) {
            ll p = factors[0], q = factors[1];

            ll fp = mp[p], fq = mp[q];
            ll f1 = mp[1];
            
            ans += cnt * (cnt + 1)/2;
            ans += cnt * f1;
            if(p != q) ans += cnt * (fp + fq);
            else ans += cnt * fp;
        }
        else if(factors.size() == 1){
            fprimes += cnt*(totprimes - mp[val]);
        }
    }

    cout << ans + fprimes/2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}