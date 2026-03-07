#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    inarr(a, n); inarr(b, m);
    sort(all(a)); sort(all(b));

    multiset<ll> s(all(a)), t(all(b));
    for (ll i = 0; i < n; i++) {
        ll val = a[i];
        if(t.find(val) != t.end()) {
            s.erase(s.find(val)); t.erase(t.find(val));
        }
    }
    
    map<ll, ll> mp;
    for(auto x : s) mp[x]++;

    function <bool(ll)> chk = [&] (ll n) {
        if(mp[n] > 0) {mp[n]--; return true;}
        if(n == 1) {mp[1]--; return (mp[1] > 0);}
        ll o = n/2; ll e = n - n/2;
        return (chk(o) && chk(e));
    };

    for(auto y : t) {
        if(!chk(y)) {cout << "No" << endl; return;}
    }

    for(auto [val, cnt] : mp) {
        if(cnt) {cout << "No" << endl; return;}
    }

    cout << "Yes" << endl;
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