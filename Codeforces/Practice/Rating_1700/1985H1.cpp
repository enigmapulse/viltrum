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
    vector<string> grid(n); inarr(grid, n);

    DSU st(n * m);

    auto chk = [&] (ll x, ll y) {
        bool rw = (x >= 0 && x < n);
        bool cl = (y >= 0 && y < m);
        return (rw && cl);
    };

    vector<pair<ll, ll>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] != '#') continue;
            ll val = i * m + j;
            for(auto [di, dj] : dirs) {
                if(chk(i + di, j + dj) && grid[i + di][j + dj] == '#') {
                    ll nval = (i + di) * m + (j + dj);
                    st.unite(val, nval);
                }
            }
        }
    }
    
    vector<ll> row(n, 0);
    for (ll i = 0; i < n; i++) {
        set<ll> s;
        for (ll j = 0; j < m; j++) {
            if(grid[i][j] == '#') {
                auto root = st.find(i * m + j);
                if(s.insert(root).second) {
                    row[i] += st.size[root];
                }
            }
            else {
                row[i]++;
                if(chk(i - 1, j) && grid[i - 1][j] == '#') {
                    auto root = st.find((i - 1) * m + j);
                    if(s.insert(root).second) {
                        row[i] += st.size[root];
                    }
                }
                if(chk(i + 1, j) && grid[i + 1][j] == '#') {
                    auto root = st.find((i + 1) * m + j);
                    if(s.insert(root).second) {
                        row[i] += st.size[root];
                    }
                }
            }
        }
    }
    
    vector<ll> col(m, 0);
    for (ll j = 0; j < m; j++) {
        set<ll> s;
        for (ll i = 0; i < n; i++) {
            if(grid[i][j] == '#') {
                auto root = st.find(i * m + j);
                if(s.insert(root
                ).second) {
                    col[j] += st.size[root];
                }
            }
            else {
                col[j]++;
                if(chk(i, j - 1) && grid[i][j - 1] == '#') {
                    auto root = st.find(i * m + j - 1);
                    if(s.insert(root).second) {
                        col[j] += st.size[root];
                    }
                }
                if(chk(i, j + 1) && grid[i][j + 1] == '#') {
                    auto root = st.find(i * m + j + 1);
                    if(s.insert(root).second) {
                        col[j] += st.size[root];
                    }
                }
            }
        }
    }

    cout << max(*max_element(all(row)), *max_element(all(col))) << endl;
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