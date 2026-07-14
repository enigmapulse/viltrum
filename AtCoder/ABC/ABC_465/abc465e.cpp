#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = false;
// dp[len][tight][is_zero][distinct_digits][contians_3][sum_of_digits]
ll dp[501][2][2][1024][3];

void solve() {
    string s; cin >> s;
    ll len = s.size();
    memset(dp, -1, sizeof(dp));

    auto recur = [&] (auto&& recur, ll pos, ll tight, ll is_zero, ll digits, ll sum_of_digits) -> ll {
        // base case
        if(pos == len) {
            if(is_zero) return 0;
            bool chk1 = (sum_of_digits == 0);
            bool chk2 = ((digits >> 3) & 1);
            bool chk3 = (__builtin_popcountll(digits) == 3);
            int cnt = chk1 + chk2 + chk3;
            return (cnt == 1);
        }

        if(dp[pos][tight][is_zero][digits][sum_of_digits] != -1) {
            return dp[pos][tight][is_zero][digits][sum_of_digits];
        }

        ll cnt = 0;
        int lim = (tight ? s[pos] - '0' : 9);
        for (int nxt = 0; nxt <= lim; nxt++) {
            int ntight = (tight && (nxt == lim));
            int nis_zero = (is_zero && (nxt == 0));
            ll ndigits = digits;
            if(!nis_zero) ndigits = ((1ll << nxt) | digits);
            ll nsod = (sum_of_digits + nxt) % 3;
            cnt = (cnt + recur(recur, pos + 1, ntight, nis_zero, ndigits, nsod)) % MOD;
        }
        return dp[pos][tight][is_zero][digits][sum_of_digits] = cnt;
    };
    cout << recur(recur, 0, 1, 1, 0, 0) << endl;
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