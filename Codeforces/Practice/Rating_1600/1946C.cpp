#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;

    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // so in a way we are binary searching over the value of x
    // which is basically the min size of a components after k cuts
    // I want to find the maximum value of x
    // so I need a checker function which checks if it is possible to k cuts 
    // and get the size of each component greater than equal to x
    // so I will do a dfs on the tree and see if the size of the subtree
    // is exactly y if so then make a cut
    // I will keep doing this if the final number of cuts >= k then it is true
    // other wise false
    // now dfs is thinking about the subtree but it might be the case that 
    // to ensure that the size of the subtree is >= k I need to include where
    // I am starting the dfs from. 
    // let's think more on how to implement this checker
    // now say I am dfs and at one point I find that this subtree has length > k
    // and If I go into the subtree then the size is < k then I need to make the cut there
    // only. If I always cut the moment I get the subtree size > k then that would cause trouble
    // as we might not get enough cuts. how would I check we can get the size in eactly k cuts

    auto chk = [&] (ll x) {
        // is it possible to get all componenets size >= x in k or more cuts
        vector<ll> sz(n + 1, 1); ll cnt = 0;
        function<void(ll, ll)> dfs = [&] (ll v, ll p) {
            ll sm = 1;
            for(auto child : adj[v]) {
                if(child == p) continue;
                dfs(child, v);
                sm += sz[child];
            }
            sz[v] = sm;
            if(sz[v] >= x) {
                ++cnt;
                sz[v] = 0;
            }
        };
        dfs(1, -1);
        return (cnt > k);
    };

    ll lo = 1, hi = 1e6;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
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