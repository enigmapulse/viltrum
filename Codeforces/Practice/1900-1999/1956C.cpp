#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> grid(n, vector<ll> (n, 0));

    auto fill = [&] (ll ops, ll num) {
        if(ops == 1) {
            for (ll i = 0; i < n; i++) {
                grid[num - 1][i] = i + 1;
            }
        }
        else {
            for (ll i = 0; i < n; i++) {
                grid[i][num - 1] = i + 1;
            }
        }
    };
    
    ll curr = n; ll c = 1;
    vector<pair<ll, ll>> ops;
    while(curr) {
        ops.push_back({c, curr});
        ops.push_back({3 - c, curr});
        fill(c, curr); fill(3 - c, curr);
        curr--;
    }

    ll sm = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            sm += grid[i][j];
        }
    }
    
    cout << sm << " " << ops.size() << endl;
    for (ll i = 0; i < ops.size(); i++) {
        auto [op, numb] = ops[i];
        cout << op << " " << numb << " ";
        for (ll j = 0; j < n; j++) cout << j + 1 << " ";
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