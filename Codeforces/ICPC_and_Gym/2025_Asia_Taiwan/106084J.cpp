#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    /*
    if I fix that I am starting from node u what is the min fuel that I need
    maybe we can binary search on the answer. can we define a checker function
    which finds out if we can achieve the ans if the fuel? well if it
    is possible with x then it is possible with x + 1 too. so our aim is finding
    the first true. 
    */
   ll n, k; cin >> n >> k;
   vector<vector<pair<ll, ll>>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    auto chk = [&] (ll x) {
        ll cnt = 0;
        function<void(ll, ll)> dfs = [&] (ll v, ll p) {
            ll sm = 0;
            for(auto child : adj[v]) {
                if(child.first == p) continue;
                dfs(child.first, v);
                if(sm + child.second >= x) {
                    ++cnt;
                    sm = child.second;
                }
            }
        };
        dfs(0, -1);
        return (cnt <= k);
    };

    ll lo = 1, hi = 1e16;
    while (lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
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