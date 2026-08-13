#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second

using namespace std;
bool multipleTests = false;

struct DSU {
    vector<ll> parent;
    vector<ll> size;
    vector<pll> reln; // contains {s, w}

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        reln.assign(n + 1, {1, 0}); // identity relation with itself
        iota(all(parent), 0);
    }
    
    pll inv(pll rln) {
        auto [s, w] = rln;
        return {s, -s * w};
    } 
    
    pll merge(pll reln1, pll reln2) {
        pll reln;
        reln.F = reln1.F * reln2.F;
        reln.S = reln1.F * reln2.S + reln1.S;
        return reln;
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        ll root = find(parent[v]);
        ll pv = parent[v];
        reln[v] = merge(reln[v], reln[pv]);
        parent[v] = root;
        return parent[v];
    }
    
    bool unite(ll a, ll b, pll nreln) {
        auto pa = find(a);
        auto pb = find(b);
        if (pa != pb) {
            // unrelated : no issues in joining them
            if (size[pa] < size[pb]) {
                swap(a, b);
                swap(pa, pb);
                nreln = inv(nreln);
            }
            parent[pb] = pa;
            size[pa] += size[pb];
            reln[pb] = merge(merge(inv(reln[b]), inv(nreln)), reln[a]);
            cout << "ACCEPTED" << endl;
            return true;
        }
        else {
            // if both are already related then must check
            auto creln = merge(reln[a], inv(reln[b]));
            if(creln == nreln) {
                cout << "REDUNDANT" << endl;
            }
            else cout << "REJECTED" << endl;
            return false;
        }
    }

    pll query(ll a, ll b) {
        auto pa = find(a);
        auto pb = find(b);
        if(pa != pb) return {0, 0};
        return merge(reln[a], inv(reln[b]));
    }
};


void solve() {
    ll n, q; cin >> n >> q;
    DSU st(n);

    while (q--) {
        ll type; cin >> type;
        ll u, v; cin >> u >> v;
        if(type == 1) {
            ll s, w; cin >> s >> w; 
            st.unite(u, v, {s, w});
        }
        else {
            auto pr = st.query(u, v);
            if(pr.F == 0) cout << "UNKNOWN" << endl;
            else cout << pr.F << " " << pr.S << endl;
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