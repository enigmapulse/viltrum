#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

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
    ll n, q; cin >> n >> q;
    DSU s(n);
    vector<ll> col(n + 1, 0); iota(all(col), 0); // color of cell i
    vector<ll> sz(n + 1, 1); // size of all elements with color i

    auto chk = [&] (ll i) {return (i > 0 && i <= n);};

    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll x, c; cin >> x >> c;
            sz[col[s.find(x)]] -= s.size[s.find(x)];
            col[x] = c;
            if(chk(x - 1) && col[x - 1] == c) s.unite(x, x - 1);
            if(chk(x + 1) && col[x + 1] == c) s.unite(x, x + 1);
            col[s.find(x)] = c;
            sz[c] += s.size[s.find(x)];
        }
        else {
            ll y; cin >> y;
            cout << sz[y] << endl;
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