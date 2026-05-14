#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll x, y; cin >> x >> y;

    vector<vector<ll>> adj(x + y + 1);
    
    if((x + y) & 1) y--;
    else x--;
    if(x < 0 || y < 0) {
        cout << "NO" << endl;
        return;
    }
    if(x > y) {
        cout << "NO" << endl;
        return;
    }
    
    // excess odd
    for (ll i = x + x + 1; i <= y + x; i++) {
        adj[x + y + 1].push_back(i);
    }
    
    // equal odd and even
    for (ll i = 1; i <= 2*x; i+=2) {
        adj[x + y + 1].push_back(i);
        adj[i].push_back(i + 1);
    }
    
    cout << "YES" << endl;
    for (ll i = 1; i <= x + y + 1; i++) {
        for(auto v : adj[i]){
            ll u = (i + 1) % (x + y + 1);
            ll m = (v + 1) % (x + y + 1);
            if(u == 0) u = x + y + 1; 
            if(m == 0) m = x + y + 1; 
            cout << u << " " << m << endl;
        }
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