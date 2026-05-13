#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> h(n), val(n);
    inarr(h, n); inarr(val, n);

    vector<ll> dp(n, 0); // max val we can get ending at i
    dp[0] = val[0];

    map<ll, ll> mp; // best value of y we can get for a particular h
    mp[h[0]] = dp[0];

    auto q = [&] (ll h) {
        auto it = mp.lower_bound(h);
        if(it == mp.begin()) return 0LL;
        else return prev(it) -> second;
    };

    auto ins = [&] (ll nh, ll nv) {
        auto it = mp.lower_bound(nh);

        if(it != mp.begin()) {
            auto prev_it = prev(it);
            if(prev_it->second >= nv) return; // dominated
        }

        while(it != mp.end() && it->second <= nv) {
            it = mp.erase(it);
        }

        mp[nh] = nv;
    };

    for (ll i = 1; i < n; i++) {
        // here dp[i] = max (dp[j] such that h[j] < h[i]) + val[i]
        dp[i] = q(h[i]) + val[i];
        ins(h[i], dp[i]);
    }
    
    cout << *max_element(all(dp)) << endl;
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