#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1); inarr(a, n);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);    
    }
    
    // here say we store in dp[v] count of all the paths
    // starting from v and are valid fibonacci paths
    // here we will pass in dfs what is the value of the node we are expecting
    // so we will init with dfs(1, -1); when expecting value is -1 then there
    // is no restriction on the value of the node there. otherwise if it is something
    // what we want then we would update the value of the target and call the child
    // if I have a valid fibonacci path
    // say I have the longest fibonacci path possible from u 
    // there could be multiple such paths
    // not exactly the longest I need the ones which reach a dead end
    // and then all the subpaths possible in there
    // however this might overcount the total number of path
    // since they may overlap how to overcome those
    // I need ways to combine the number of paths from the children to the parent node
    // now ideally I would have simply done the sum of all paths
    // but there is a catch there are paths without any restrictions too which would get added
    // say I am counting all the valid paths from v
    // then there are paths of size 2 which would be equal to number of children
    // any longer path must have the third element equal to the sum of a[v] and a[child]
    // what if I construct a map for each next element from u and the number of path from there
    // transitioning over edges seems sensible
    // dp(u -> v) = 1 + sigma dp(v -> w) where a[w] = a[u] + a[v]
    // now I cannot do a double dimension dp since n is till 1e5
    // so we make dp[u] as a map
    // alright what's the base case
    
    vector<map<ll, ll>> dp(n + 1);

    function <void(ll, ll)> dfs = [&] (ll v, ll p) {
        for(auto child : adj[v]) {
            if(child == p) continue;
            dp[v][child] = 1;
            dfs(child, v);
            for(auto w : adj[child]) {
                if(dp[child].find(w) != dp[child].end() && a[w] == a[child] + a[v])
                    dp[v][child] += dp[child][w]; 
            }
        }
    };

    for (ll i = 1; i <= n; i++) {
        dfs(i, -1);
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