#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;
    ll n = s.size();

    vector<set<ll>> idx(26);
    for (ll i = 0; i < n; i++) {
        idx[s[i] - 'a'].insert(i);
    }

    vector<ll> dp(n, 0);
    if(t.size() == 1 && s[0] == t[0]) dp[0] = 1;

    for (ll i = 1; i < n; i++) {
        ll curr = i + 1; bool empty = false;
        for (ll j = t.size() - 1; j >= 0; j--) {
            if(idx[t[j] - 'a'].empty()) {empty = true; break;}
            auto it = idx[t[j] - 'a'].lower_bound(curr);
            if(it == idx[t[j] - 'a'].begin()) {empty = true; break;}
            curr = *prev(it);
        }
        if(empty) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + curr + 1;
    }
    
    ll tot = (n * (n + 1)) / 2;
    cout << tot - dp[n - 1] << endl;
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