#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(2 * n); inarr(a, 2 * n);

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < 2 * n; i++) {
        mp[a[i]].push_back(i);
    }

    map<pair<ll, ll>, ll> score;

    set<pair<ll, pll>, greater<>> s;
    for(auto [val, range] : mp) {
        ll l = range[0], r = range[1];
        ll prod = (r - l + 1) * (r - l + 1);
        pll pr = {l, r};
        s.insert({prod, pr});
        score[pr] = prod;
    }

    ll ans = 0;
    while(!s.empty()) {
        auto it = s.begin();
        auto range = it -> second;
        ans += it -> first;
        for(ll idx = range.first + 1; idx < range.second; idx++) {
            ll curr_score = score[];
        }
    }
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