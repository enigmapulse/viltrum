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

ll modinv(ll div) {
    return binpow(div, MOD - 2);
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    vector<ll> zero, ones;
    ll idx = 0;
    while(idx < n) {
        ll sz = 1;
        while(idx < n - 1 && s[idx] == s[idx + 1]) {sz++; idx++;}
        if(s[idx] == '0') zero.push_back(sz);
        else ones.push_back(sz);
        idx++;
    }

    ll ans = 0;
    {
        ll m = zero.size();
        ll sm = accumulate(all(zero), 0ll);
        sm -= m;
        ll val = 1;
        ll top = sm + m - 1;
        ll big = max(sm, m - 1);
        ll small = min(sm, m - 1);
        for (ll i = top; i > big; i--) {
            val = (val * i) % MOD;
        }
        for (ll i = 2; i <= small; i++) {
            val = (val * modinv(i)) % MOD;
        }
        ans = val;
    }

    {
        ll m = ones.size();
        ll sm = accumulate(all(ones), 0ll);
        sm -= m;
        ll val = 1;
        ll top = sm + m - 1;
        ll big = max(sm, m - 1);
        ll small = min(sm, m - 1);
        for (ll i = top; i > big; i--) {
            val = (val * i) % MOD;
        }
        for (ll i = 2; i <= small; i++) {
            val = (val * modinv(i)) % MOD;
        }
        ans = (ans * val) % MOD;
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