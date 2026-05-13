#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> cnt(4);
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        cnt[x]++;
    }
    
    // can also be done with a loop from k -> j -> i
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n + 1, vector<double> (n + 1, -1)));
    function<double(ll, ll, ll)> f = [&] (ll one, ll two, ll three) {
        if(one == 0 && two == 0 && three == 0) return 0.000;
        if(one < 0 || two < 0 || three < 0) return 0.000;
        if(dp[one][two][three] != -1) return dp[one][two][three];
        double c1 = (one * f(one - 1, two, three));
        double c2 = (two * f(one + 1, two - 1, three));
        double c3 = (three * f(one, two + 1, three - 1));
        double c4 = n;
        return dp[one][two][three] = (c1 + c2 + c3 + c4) / (one + two + three);
    };

    cout << fixed << setprecision(10) << f(cnt[1], cnt[2], cnt[3]) << endl;
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