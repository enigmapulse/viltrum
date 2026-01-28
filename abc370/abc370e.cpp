#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> dp(n + 1, 0);

    vector<ll> a(n); inarr(a, n);
    vector<ll> pre(n);
    for (ll i = 1; i < n; i++) pre[i] += pre[i - 1];

    map<ll, vector<ll>> mp;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n; i++) {
        mp[pre[i]].push_back(i);

    }
    
    // I can calculate all the ranges which have length equal to k, now I 
    // need to count all partitions containing these ranges , pie works but that
    // would be too difficult to do properly
    // there are going 
    // dp[index][state] state = 0/1 index i considered
    // state = 1 if a segment of length k has already come
    // state = 0 if no segment of length k is there
    // dp[i][1] = all j such that i to j sum is k -> (dp[i - j][0] + dp[i - j][1]) = 2^(j)
    // + all j such that j < i dp[j][1]
    // dp[i][0] = all j such that i to j is not equal to k dp[j][0]
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