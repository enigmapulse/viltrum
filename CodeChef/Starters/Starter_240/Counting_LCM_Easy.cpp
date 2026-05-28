#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

const ll MAXN = 1000005;
ll spf[MAXN], c[MAXN];

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

void compute() {
    c[0] = 0; c[1] = 1;
    for (ll L = 2; L < MAXN; L++) {
        ll p = spf[L];
        ll cnt = 0, val = L;
        while(val % p == 0) {
            val = val / p;
            cnt++;
        }
        c[L] = (2 * cnt + 1) * c[val];
    }

    for (ll L = 2; L < MAXN; L++) {
        c[L] += c[L - 1];
    }
}

bool multipleTests = true;

void solve() {
    ll z; cin >> z;
    cout << z * z - c[z] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; 
    sieve(); compute();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}