#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll nCr (ll n, ll r) {
    ll val = 1;
    r = min(r, n - r);
    for (ll i = n; i > n - r; i--) {
        val = val * i;
    }
    for (ll i = 1; i <= r; i++) {
        val = val / i;
    }
    return val;
};

void solve() {
    ll u, d, p, n, s; cin >> u >> d >> p >> n >> s;

    auto fx = [&] () {
        __int128_t x = p * u + (100 - p) * d;
        x = x * n * s;
        x /= 100;
        x /= 100;
        return x;
    };

    ll best = 0;
    __int128_t curr = 0;
    for (ll i = 0; i <= n; i++) {
        __int128_t val = nCr(n, i);
        // cerr << "i : " << i << " " << (ll)val << endl;
        for (ll j = 1; j <= i; j++) val = val * p;
        for (ll j = i + 1; j <= n; j++) val = val * (100 - p);
        if(curr < val) {
            curr = val;
            best = i;
        }
    }

    // cerr << best << endl;
    
    __int128_t y = s;
    for (ll j = 1; j <= best; j++) y = y * u;
    for (ll j = best + 1; j <= n; j++) y = y * d;
    for (ll i = 0; i < n; i++) y = y / 100;
    ll x= fx();

    cout << x << " " << (ll)y << " " << x * (ll)y * 10 << endl; 
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