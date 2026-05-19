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
    vector<ll> perm(n + 1); iota(all(perm), 0);
    vector<bool> chk(n + 1, false); chk[1] = true;

    if(n == 2) {
        cout << "1 2" << endl;
    }
    else if(n == 3) {
        cout << "1 2 3" << endl;
    }
    else if(n == 4) {
        cout << "1 4 3 2" << endl;
    }
    else if (n == 5) {
        cout << "1 4 3 2 5" << endl;
    }
    else if (n == 6) {
        cout << "1 4 6 2 5 3" << endl;
    }
    else {
        for (ll i = (n / 2); i > 1; i--) {
            if(spf[i] == i) {
                vector<ll> chosen;
                for (ll j = i; j <= n; j+=i) {
                    if(!chk[j]) {
                        chosen.push_back(j);
                        chk[j] = true;
                    }
                }
                for (ll j = 0; j < chosen.size() - 1; j++) {
                    swap(perm[chosen[j]], perm[chosen[j + 1]]);
                }
            }
        }
        
        for (ll i = 1; i <= n; i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
    }
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