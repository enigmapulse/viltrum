#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

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

ll modinv (ll x) {
    return binpow(x, MOD - 2);
}

ll frac(ll num, ll denom) {
    num = num % MOD;
    denom = denom % MOD;
    return (num * (modinv(denom)) % MOD);
}

typedef vector<vector<ll>> matrix;

matrix mul(matrix a, matrix b) {
    ll lim = a.size();
    matrix c(lim, vector<ll> (lim, 0));
    for (ll i = 0; i < lim; i++) {
        for (ll j = 0; j < lim; j++) {
            for (ll k = 0; k < lim; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix matpow(matrix base, ll exp) {
    ll lim = base.size();
    matrix res(lim, vector<ll> (lim, 0));
    for (ll i = 0; i < lim; i++)
    {
        res[i][i] = 1;
    }
    
    while (exp > 0) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}

bool multipleTests = false;

void solve() {
    ll a, b, k, n; cin >> a >> b >> k >> n;

    ll ph = frac(a, b);
    ll pt = frac(b - a, b);
    vector<ll> bc(k, 1);
    reverse(all(bc));

    if(n < k) {
        cout << bc[k - n] << endl;
        return;
    }

    matrix mat(k, vector<ll> (k, 0));
    for (ll i = 1; i < k; i++) {
        mat[i][i - 1] = 1;
    }
    mat[0][0] = pt;
    for (ll j = 1; j < k; j++) {
        mat[0][j] = (mat[0][j - 1] * ph) % MOD;
    }
    
    mat = matpow(mat, n - k + 1);
    ll ans = 0;
    for (ll i = 0; i < k; i++) {
        ans = (ans + (bc[i] * mat[0][i]) % MOD) % MOD;
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