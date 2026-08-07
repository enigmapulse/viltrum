#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> type(n + 1); inarr(type, n);
    vector<ll> cold(k + 1); inarr(cold, k);
    vector<ll> hot(k + 1); inarr(hot, k);

    // the index of the last task assigned to worker 1 and worker 2
    // dp[i][j] i > j always
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
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