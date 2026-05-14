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
    vector<multiset<ll>> a(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll x; cin >> x;
            a[i].insert(x);
        }
    }
    
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++) {
        vector<ll> del;
        for(auto x : a[i]) {
            auto it = a[i + 1].find(x);
            if(it != a[i + 1].end()) {
                cnt++; del.push_back(*it);
                a[i + 1].erase(it);
            }
        }
        for(auto y : del) {
            a[i + 1].insert(y);
        }
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