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

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    bool chk = false;
    set<ll> ret;
    auto add = [&] (ll n) {
        while (n != 1) {
            if(ret.find(spf[n]) != ret.end()) chk = true;
            ret.insert(spf[n]);
            ll val = spf[n];
            while(n % val == 0) n /= val;
        }
    };

    for (ll i = 0; i < n; i++) {
        add(a[i]);
        if(chk) {
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; sieve();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}