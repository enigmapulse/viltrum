#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(k), b(k); inarr(a, k); inarr(b, k);

    vector<string> grid(n + 1, string(n + 1, ' '));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    
    map<ll, set<ll>> mp;
    function <void(ll)> recur = [&] (ll x) {
        for(ll i = 1; i <= n; ++i) {
            char c = grid[x][i];
            if(c == '1' && mp[i].find(x) == mp[i].end()) {
                mp[i].insert(x);
                recur(x);
            }
        }
    };

    for(auto y : a) {
        recur(y);
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