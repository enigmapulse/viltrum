#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

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

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    map<ll, ll> freq;
    for(auto x : a) freq[x]++;

    ll tot = 1;
    for(auto [val, f] : freq) {
        tot = (tot * binpow(2, f - 1)) % MOD;
    }

    ll cnt = tot;
    for (ll i = 0; i < n - 1; i++) {
        if(freq[-1] != 0 && a[i + 1] - a[i] == 1) {
            cnt = (cnt + tot) % MOD;
        }
    }

    cout << cnt << endl;
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