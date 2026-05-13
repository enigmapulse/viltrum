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
    
    vector<pair<ll, ll>> pts(n);
    for (ll i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    
    vector<bool> vis(n, false);
    vector<ll> route; route.reserve(n);
    
    ll curr = 0;
    vis[curr] = true;
    route.push_back(1); 
    
    for (ll step = 1; step < n; step++) {
        ll dst = -1, nxt = -1;
        for (ll i = 0; i < n; i++) {
            if (!vis[i]) {
                ll dist = abs(pts[curr].first - pts[i].first) + abs(pts[curr].second - pts[i].second);
                if (dst == -1 || dist < dst) {
                    dst = dist;
                    nxt = i;
                }
            }
        }
        
        vis[nxt] = true;
        route.push_back(nxt + 1); 
        curr = nxt;
    }
    
    for (ll i = 0; i < n; i++) {
        cout << route[i] << " ";
    }
    cout << endl;
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