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
    vector<ll> a(n); inarr(a, n);

    vector<vector<ll>> b(60, vector<ll> (n + 1, 0));
    for (ll i = 1; i <= n; i++) {
        ll val = a[i - 1];
        for (ll j = 0; j < 60; j++) {
            if((val >> j) & 1) b[j][i] = 1;
        }
    }
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < 60; j++) {
            b[j][i] += b[j][i - 1];
        }
    }

    // for (ll j = 0; j < 60; j++) {
    //     for (ll i = 0; i <= n; i++) {
    //         cout << b[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    
    
    set<ll> ors;

    for (ll i = 0; i < n; i++) {
        ors.insert(a[i]);
    }
    

    for (ll i = 1; i <= n; i++) {
        // i is the starting position
        set<ll> idx;
        for (ll j = 0; j < 60; j++) {
            if (b[j][n] - b[j][i - 1] > 0) {
                auto it = lower_bound(all(b[j]), b[j][i - 1] + 1);
                idx.insert(it - b[j].begin());
            }
        }

        ll curr = 0;
        for(auto id : idx) {
            curr |= a[id - 1];
            ors.insert(curr);
        }
    }
    
    
    cout << ors.size() << endl;
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