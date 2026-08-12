#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

const ll MOD = 1000000007;

struct Matrix {
    int r, c;
    vector<vector<ll>> mat;

    Matrix(int _r, int _c) {
        r = _r;
        c = _c;
        mat.assign(r, vector<ll>(c, 0));
    }

    static Matrix identity(int n) {
        Matrix res(n, n);
        for (int i = 0; i < n; i++) {
            res.mat[i][i] = 1;
        }
        return res;
    }

    Matrix operator*(const Matrix &other) const {
        assert(c == other.r);
        Matrix res(r, other.c);
        for (int i = 0; i < r; i++) {
            for (int k = 0; k < c; k++) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < other.c; j++) {
                    res.mat[i][j] += (mat[i][k] * other.mat[k][j]) % MOD;
                    res.mat[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix a, ll b) {
    assert(a.r == a.c);
    Matrix res = Matrix::identity(a.r);
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


void solve() {
    ll m, n; cin >> m >> n;
    vector<ll> s(m), l(m); 
    inarr(s, m); inarr(l, m);

    Matrix A(m, 2), B(2, m);
    // writing A and B
    for (ll i = 0; i < m; i++) {
        A.mat[i][0] = s[i];
        A.mat[i][1] = l[i];
        B.mat[0][i] = s[i] + l[i];
        B.mat[1][i] = s[i];
    }
    
    Matrix C = B * A;
    C = power(C, n - 1);
    Matrix D(1, 2);
    D.mat[0][0] = s[0];
    D.mat[0][1] = l[0];
    Matrix fin = (C * B);
    fin = D * fin;

    ll ans = 0;
    for (auto x : fin.mat[0]) ans = (ans + x) % MOD;
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