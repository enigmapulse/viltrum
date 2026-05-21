#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;
#define pll pair<ll, ll>
#define f first
#define s second

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
    ll n, q; cin >> n >> q;

    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);
    vector<ll> oa = a, ob = b;
    sort(all(a)); sort(all(b));

    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        ans = (ans * min(a[i], b[i])) % MOD;
    }
    cout << ans << " ";

    while(q--) {
        ll o, x; cin >> o >> x;
        if(o == 1) {
            ll val = oa[x - 1];
            auto it = upper_bound(all(a), val); it--;
            ll idx = it - a.begin();
            ll prev = min(a[idx], b[idx]);
            a[idx]++; oa[x - 1]++;
            ll curr = min(a[idx], b[idx]);
            ans = ((((ans * curr) % MOD) * modinv(prev)) % MOD);
        }
        else {
            ll val = ob[x - 1];
            auto it = upper_bound(all(b), val); it--;
            ll idx = it - b.begin();
            ll prev = min(a[idx], b[idx]);
            b[idx]++; ob[x - 1]++;
            ll curr = min(a[idx], b[idx]);
            ans = ((((ans * curr) % MOD) * modinv(prev)) % MOD);
        }

        cout << ans << " ";
    }
    cout << endl;
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