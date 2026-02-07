#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define INF 1e18

using namespace std;

bool multipleTests = false;

/*
so the value of a_i mod M must be the same as the value at a_i + L mod m
so here if I fix the value of the mod of the first L values does it fix the ops
required for the rest of the array. I can just bruteforce and check how much cost
I am getting on choosing a particular val mod M. so I need to somehow find out 
which setting gives me the minimum value
so for all pref[i] where i can be from 0 to l - 1 I store the sum till there mod M
*/

void solve() {
    ll n, m, l; cin >> n >> m >> l;
    vector<ll> a(n); inarr(a, n);

    vector<vector<ll>> dp(l, vector<ll> (m, INF));

    auto ops = [&] (ll idx, ll mod) {
        ll cnt = 0;
        for (ll i = idx; i < n; i += l) {
            if(mod >= a[i] % m) cnt += mod - a[i] % m;
            else cnt += m - a[i] % m + mod;
        }
        return cnt;
    };

    for (ll j = 0; j < m; j++) {
        dp[0][j] = ops(0, j);
    }

    for (ll i = 1; i < l; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll k = 0; k < m; k++) {
                dp[i][(j + k) % m] = min(dp[i][(j + k) % m], dp[i - 1][j] + ops(i, k));
            }
        }
    }
    
    cout << dp[l - 1][0] << endl;
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