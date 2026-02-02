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
    vector<pll> a(n);

    ll lo = 1, hi = 0;
    for (ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        a[i] = {u, v};
        hi += u;
    }

    // auto cmp = [&] (pll a, pll b) {
    //     ll x1 = a.second - a.first;
    //     ll x2 = b.second - b.first;
    //     if(x1 == x2) return a.first < b.first;
    //     else return (x1 < x2);
    // };
    
    sort(all(a));

    auto chk = [&] (ll x) {
        for(auto [c, d] : a) {
            if (x >= c) x -= d;
            else return false;
        }
        return true;
    };


    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << lo << endl;
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