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
    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i <= n; i++) {
        ll sz; cin >> sz;
        for (ll j = 0; j < sz; j++) {
            ll x; cin >> x;
            adj[x].push_back(i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << adj[i].size() << " ";
        for(auto x : adj[i]) cout << x << " ";
        cout << endl;
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