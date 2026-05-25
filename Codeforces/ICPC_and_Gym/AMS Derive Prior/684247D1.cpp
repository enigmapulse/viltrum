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
    matrix c(3, vector<ll> (3, 0));
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 3; j++) {
            for (ll k = 0; k < 3; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix matpow(matrix base, ll exp) {
    matrix res = {{1,0,0}, {0,1,0}, {0,0,1}};
    while (exp > 0) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp /= 2;
    }
    return res;
}

bool multipleTests = false;

void solve() {
    ll a, b, n; cin >> a >> b >> n;

    ll ph = frac(a, b);
    ll pt = frac(b - a, b);
    vector<ll> bc =  {1, 1, (pt * (1 + ph)) % MOD};
    reverse(all(bc));

    if(n <= 2) {
        cout << bc[2 - n] << endl;
        return;
    }

    matrix mat(3, vector<ll> (3, 0));
    mat[0][1] = pt;
    mat[0][2] = (ph * ((pt * pt) % MOD)) % MOD;
    mat[1][0] = 1;
    mat[2][1] = 1;
    mat = matpow(mat, n - 2);

    ll ans = 0;
    for (ll i = 0; i < 3; i++) {
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