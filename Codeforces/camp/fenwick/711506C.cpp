#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

struct TREE {
    ll n;
    vector<ll> st;

    TREE(ll _n) {
        n = _n;
        st.assign(n + 1, 0);
    }

    void update(ll idx, ll val) {
        while (idx <= n) {
            st[idx] += val;
            idx += idx & -idx;
        }
    }

    ll sum(ll idx) {
        ll sm = 0;
        while (idx > 0) {
            sm += st[idx];
            idx -= idx & -idx;
        }
        return sm;
    }
};

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1); inarr(a, n);

    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, 1));
    for (ll j = 0; j <= k; j++) dp[0][j] = 0;
    vector<TREE> q(k + 1, TREE(n));
    
    for (ll idx = 1; idx <= n; idx++) {
        dp[idx][0] = 1;
        q[0].update(a[idx], 1);
        for (ll sz = 1; sz <= k; sz++) {
            dp[idx][sz] = q[sz - 1].sum(a[idx] - 1);
            q[sz].update(a[idx], dp[idx][sz]);
        }   
    }

    cout << q[k].sum(n) << endl;
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