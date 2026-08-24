#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;
ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return res;
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    ll sz = 64 - __builtin_clzll(n);
    string s = "";
    for (int i = sz - 1; i >= 0; i--) {
        s += ((n >> i) & 1) ? '1' : '0';
    }

    vector<vector<ll>> dp(4, vector<ll> (sz, 0));
    dp[1][0] = 1;
    for (ll i = 1; i < sz; i++) {
        if(s[i] == '1') {
            dp[0][i] = 0;
            dp[1][i] = (dp[1][i - 1] + dp[0][i - 1]);
            dp[2][i] = dp[0][i - 1];
            dp[3][i] = (dp[1][i - 1] + dp[2][i - 1]);
        }
        else {
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]);
            dp[1][i] = dp[0][i - 1];
            dp[2][i] = (dp[2][i - 1] + dp[1][i - 1]);
            dp[3][i] = dp[1][i - 1];            
        }
    }
    
    ll p = dp[1][sz - 1];
    ll cnt = 0;
    while(p > 0 && p % 3 == 0) {
        cnt++; p = p / 3;
    }

    cout << (p % MOD + (sz - 1 - cnt) + MOD) % MOD << endl;
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