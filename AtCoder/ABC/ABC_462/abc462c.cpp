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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        auto it = mp.lower_bound(x);
        if(it != mp.begin()) {
            auto ut = prev(it);
            if(ut -> second <= y) continue;
        }
        while(it != mp.end() && it -> second >= y) it = mp.erase(it);
        mp[x] = y;
    }
    
    cout << mp.size() << endl;
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