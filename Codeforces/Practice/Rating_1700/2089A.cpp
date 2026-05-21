#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

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

bool multipleTests = true;

void solve() {
    ll n; cin >> n;

    if(n == 2) {
        cout << "2 1" << endl;
        return;
    }
    else if(n == 3) {
        cout << "2 1 3" << endl;
        return;
    }

    ll cnt = 0, p = 0;
    for (ll i = 1; i < (n + 3)/2; i++) {
        if(spf[i] == i) p = max(p, i);
    }
    
    vector<ll> perm(n);
    for (ll i = 0; i < p; i++) {
        perm[2 * i] = p + i;
        if(i != p - 1) perm[2 * i + 1] = p - i - 1;
    }
    for (ll i = 2 * p - 1; i < n; i++) perm[i] = i + 1; 

    for (ll i = 0; i < n; i++) cout << perm[i] << " ";
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