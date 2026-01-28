#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), x(n); inarr(x, n); inarr(a, n);

    vector<vector<ll>> b(64, vector<ll> (n + 1));
    for (ll i = 0; i < n; i++) b[0][i + 1] = x[i];
    
    for (ll row = 1; row < 64; row++) {
        for (ll i = 1; i <= n; i++) {
            b[row][i] = b[row - 1][b[row - 1][i]];
        }
    }
    
    vector<ll> ans(n, 0);
    for (ll i = 0; i < n; i++) {
        ll curr = i + 1;
        for (ll idx = 0; idx < 64; idx++) {
            if((k >> idx) & 1) {
                curr = b[idx][curr];
            }
        }
        ans[i] = a[curr - 1];
    }

    for(auto an : ans) cout << an << " ";
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