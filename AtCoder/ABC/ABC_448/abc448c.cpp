#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    set<pll> s, t; vector<ll> c(n);
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x; c[i] = x;
        s.insert({x, i + 1});
        t.insert({i + 1, x});
    }

    auto del = [&] (ll idx) {
        auto it = t.lower_bound({idx, -1});
        auto ut = s.find({it -> S, it -> F});
        t.erase(it); s.erase(ut);
    };

    auto add = [&] (ll idx) {
        t.insert({idx, c[idx - 1]});
        s.insert({c[idx - 1], idx});
    };
    
    while(q--) {
        ll sz; cin >> sz;
        vector<ll> idx;
        for (ll i = 0; i < sz; i++) {
            ll y; cin >> y;
            idx.push_back(y);
        }
        
        for(auto i : idx) del(i);
        cout << s.begin()->F << endl;
        for(auto i : idx) add(i);
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