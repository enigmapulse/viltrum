#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

struct DSU {
    vector<ll> parent;
    vector<ll> size, sm;

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);struct DSU {
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
        sm.assign(n + 1, 0);
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
            sm[a] += sm[b];
            return true;
        }
        return false;
    }
};

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;

    DSU s(n);
    vector<ll> col(n + 1, 0);

    while(q--) {
        ll ops; cin >> ops;

        if(ops == 1) {
            ll u, v; cin >> u >> v;
            s.unite(u, v);
        }
        else if(ops == 2) {
            ll v; cin >> v;
            if(col[v]) s.sm[s.find(v)]--;
            else s.sm[s.find(v)]++;
            col[v] = col[v] ^= 1;
        }
        else {
            ll v; cin >> v;
            if(s.sm[s.find(v)] > 0) cout << "Yes" << endl;
            else cout << "No" << endl;
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