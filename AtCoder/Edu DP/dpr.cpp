#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;

    ll dp[n][n][61];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) cin >> dp[i][j][0]; 
    }
    
    // dp[i][j][k] = number of paths of length (1 << k) starting from i ending at j
    // dp[u][v][w] = sum of dp[u][i][w - 1] * dp[i][v][w - 1] this is basically matrix mul

    for (ll w = 1; w <= 60; w++) {
        for (ll u = 0; u < n; u++) {
            for (ll v = 0; v < n; v++) {
                ll sm = 0;
                for (ll i = 0; i < n; i++) {
                    ll mul = (dp[u][i][w - 1] * dp[i][v][w - 1]) % MOD;
                    sm = (sm + mul) % MOD;
                }
                dp[u][v][w] = sm;
            }
        }
    }
    
    vector<vector<ll>> paths(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) paths[i][i] = 1; 
    for (ll bit = 0; bit <= 60; bit++) {
        if ((k >> bit) & 1) {
            vector<vector<ll>> nxt(n, vector<ll>(n, 0));
            for (ll i = 0; i < n; i++) {
                for (ll j = 0; j < n; j++) {
                    ll sm = 0;
                    for (ll mid = 0; mid < n; mid++) {
                        ll mul = (paths[i][mid] * dp[mid][j][bit]) % MOD;
                        sm = (sm + mul) % MOD;
                    }
                    nxt[i][j] = sm;
                }
            }
            paths = nxt;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ans = (ans + paths[i][j]) % MOD;
        }
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