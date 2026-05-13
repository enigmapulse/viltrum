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
    vector<ll> a(n); inarr(a, n);

    vector<ll> prev(k + 1, 0), curr(k + 1), pre_prev(k + 1, 0), pre_curr(k + 1, 0);

    // init
    for (ll j = 0; j <= k; j++) {
        prev[j] = (j <= a[0]) ? 1 : 0;
        if (j == 0) pre_prev[j] = prev[j];
        else pre_prev[j] = (pre_prev[j - 1] + prev[j]) % MOD;
    }
    
    for (ll i = 1; i < n; i++) {
        for (ll j = 0; j <= k; j++) {
            ll sub = (j - a[i] > 0) ? pre_prev[j - a[i] - 1] : 0;
            curr[j] = (pre_prev[j] - sub + MOD) % MOD;
            if(j == 0) pre_curr[j] = curr[j] % MOD;
            else pre_curr[j] = (pre_curr[j - 1] + curr[j]) % MOD;
        }
        swap(prev, curr);
        swap(pre_prev, pre_curr);
    }
    
    cout << prev[k] << endl;
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