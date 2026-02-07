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

    vector<pll> a(n, {0, 0}); map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        ll u, v; cin >> u >> v;
        a[i] = {u, v};
        mp[v].push_back(u);
    }

    sort(all(a));

    map<ll, vector<ll>> curr;
    for(auto [u, v] : a) curr[v].push_back(u);
    
    for(auto [col, vec] : mp) {
        if(vec != curr[col]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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