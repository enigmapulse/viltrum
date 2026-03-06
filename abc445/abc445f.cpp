#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e16;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, path; cin >> n >> path;
    vector<vector<vector<ll>>> adj(n + 1, vector<vector<ll>> (n + 1, vector<ll> (40, INF)));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) cin >> adj[i][j][0];
    }
    
    for (ll pow = 1; pow < 40; pow++) {
        for (ll k = 1; k <= n; k++) {
            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j <= n; j++) {
                    adj[i][j][pow] = min(adj[i][j][pow], adj[i][k][pow - 1] + adj[k][j][pow - 1]);
                }
            }
        }
    }
    
    vector<vector<ll>> ans(n + 1, vector<ll> (n + 1, INF)), nans(n + 1, vector<ll> (n + 1, INF));
    for (ll i = 1; i <= n; i++) ans[i][i] = 0;
    
    for (ll bit = 0; bit < 40; bit++) {
        if((path >> bit) & 1) {
            for (ll k = 1; k <= n; k++) {
                for (ll i = 1; i <= n; i++) {
                    for (ll j = 1; j <= n; j++) {
                        if (ans[i][k] != INF && adj[k][j][bit] != INF)
                            nans[i][j] = min(nans[i][j], ans[i][k] + adj[k][j][bit]);
                    }
                }
            }   
            
            ans = nans;
            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j <= n; j++) {
                    nans[i][j] = INF;
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++) cout << ans[i][i] << endl;
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