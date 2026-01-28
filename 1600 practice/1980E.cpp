#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

struct DSU {
    vector<ll> parent;
    vector<ll> size;

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

void solve() {
    ll n, m; cin >> n >> m;

    DSU s(n*m), t(n*m);
    vector<vector<ll>> grid1(n, vector<ll> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid1[i][j]; 
            s.unite(grid1[i][0], grid1[i][j]);  
        }
    }

    for (ll j = 0; j < m; j++) {
        for (ll i = 0; i < n; i++) {
            t.unite(grid1[0][j], grid1[i][j]);
        }
    }
    
    bool val = true;
    vector<vector<ll>> grid2(n, vector<ll> (m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid2[i][j]; 
            val &= (s.find(grid2[i][0]) == s.find(grid2[i][j]));  
        }
    }

    for (ll j = 0; j < m; j++) {
        ll root = t.find(grid2[0][j]);
        for (ll i = 0; i < n; i++) {
            val &= (t.find(grid2[i][j]) == root);
        }
    }

    if(val) cout << "YES" << endl;
    else cout << "NO" << endl;
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
