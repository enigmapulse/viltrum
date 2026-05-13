#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

ll dp[3000][3000][2];
bool vis[3000][3000][2] = {};

ll f (ll l, ll r, ll turn, const vector<ll>& a) {
    if(vis[l][r][turn]) return dp[l][r][turn];
    if(turn == 0) {
        if(l == r) return a[l];
        vis[l][r][turn] = true;
        return dp[l][r][turn] = max(a[l] + f(l + 1, r, turn ^ 1, a), a[r] + f(l, r - 1, turn ^ 1, a));
    }
    else {
        if(l == r) return -a[l];
        vis[l][r][turn] = true;
        return dp[l][r][turn] = min( - a[l] + f(l + 1, r, turn ^ 1, a), -a[r] + f(l, r - 1, turn ^ 1, a));
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    cout << f(0, n - 1, 0, a) << endl;
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