#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

/*
    the one with the max successors would be the root
    if there are multiple then not possible
    the next max one is definintely the root's child
    if there are multiple they are all root's child
    apart from that the toher child may have less vertices so
    they can't be found out using this heuristic
    if I have fiund out one child and marked them all then among the
    remaining ones the ones with the max successors is the other child
    so this is a recursive process
    */

void solve() {
    ll n; cin >> n;

    ll root = 0, mx = 0;
    set<ll> nodes; vector<vector<ll>> child(n + 1); 
    for (ll i = 1; i <= n; i++) {
        nodes.insert(i);
        ll m; cin >> m;
        if(m > mx) {
            root = i; mx = m;
        }
        vector<ll> c(m); inarr(c, m);
        child[i] = c;
    }
    nodes.erase(root);
    vector<vector<ll>> adj(n + 1); 
    
    // I will iterate over all the children of root and whoever is max would
    // be my child. then I will iterate over all the children of that children
    // and so forth
    function <void(ll)> recur = [&] (ll v) {
        ll c = 0; ll maxi = 0;
        for(auto succ : child[v]) {
            if(child[succ].size() > maxi) {
                maxi = child[succ].size(); c = succ;
            }
        }
    };
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