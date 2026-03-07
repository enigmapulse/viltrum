#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> a(n); inarr(a, n);

    ll cnt = 1;
    set<pair<ll, ll>> s, t;
    s.insert({a[0], 0}); t.insert({0, a[0]});

    auto erase1 = [&] (pair<ll, ll> p) {
        pair<ll, ll> q = {p.second, p.first};
        s.erase(p); t.erase(q);
    };

    auto erase2 = [&] (pair<ll, ll> p) {
        pair<ll, ll> q = {p.second, p.first};
        s.erase(q); t.erase(p);
    };

    auto mantain = [&] (ll idx) {
        while(!t.empty() && t.begin() -> first <= idx) erase2(*t.begin()); 
    };

    for (ll i = 1; i < n; i++) {
        s.insert({a[i], i});
        t.insert({i, a[i]});

        auto it = s.find({a[i], i});
        
        if(it != s.begin()) {
            auto ut = it; --ut; ll idx = 0;
            if(abs(ut -> first - a[i]) < d) {
                idx = ut -> second; erase1(*ut);
                mantain(idx);
            }
        }

        if(it != prev(s.end())) {
            auto ut = it; ++ut; ll idx = 0;
            if(abs(ut -> first - a[i]) < d) {
                idx = ut -> second; erase1(*ut);
                mantain(idx);
            }
        }

        assert(s.size() == t.size());
        cnt += s.size();
    }
    
    cout << cnt << endl;
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