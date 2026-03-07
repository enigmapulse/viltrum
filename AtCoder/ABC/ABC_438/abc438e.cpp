#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);

    ll up[60][n + 1], sum[60][n + 1];

    for (ll i = 1; i <= n; i++) {
        up[0][i] = a[i - 1];  
        sum[0][i] = i;    
    }

    for (ll k = 1; k < 60; k++) {
        for (ll i = 1; i <= n; i++) {
            ll mid = up[k-1][i];
            up[k][i] = up[k-1][mid];
            sum[k][i] = sum[k-1][i] + sum[k-1][mid];
        }
    }

    while(q--) {
        ll t, b; cin >> t >> b;

        ll ans = 0;
        for (ll k = 0; k < 60; k++) {
            if ((t >> k) & 1) {
                ans += sum[k][b]; 
                b = up[k][b];          
            }
        }
        cout << ans << endl;
    }    
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