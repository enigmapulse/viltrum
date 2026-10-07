#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

struct Node {
    ll val;
    // 1. Define the neutral element
    Node() { val = 0; } 
    Node(ll _val) { val = _val; }
};

struct LazySegTree {
    int n;
    vector<Node> tree;
    vector<ll> lazy;

    // 2. Define the neutral lazy value
    const ll NO_UPDATE = 0; 

    LazySegTree(int _n) {
        n = _n;
        tree.assign(4 * n, Node());
        lazy.assign(4 * n, NO_UPDATE);
    }

    // 3. How to merge two child nodes into a parent node
    Node merge(const Node& l, const Node& r) {
        Node res;
        res.val = l.val + r.val; 
        return res;
    }

    // 4. How a lazy value affects a node's data AND its pending lazy tag
    void apply(int v, int tl, int tr, ll val) {
        ll flag = (tr - tl + 1) & 1;
        tree[v].val += val * flag;
        lazy[v] += val;
    }

    // =====================================================================
    // ⚠️ DO NOT MODIFY BELOW THIS LINE DURING CONTESTS ⚠️
    // =====================================================================

    void push(int v, int tl, int tr) {
        if (lazy[v] != NO_UPDATE) {
            int tm = tl + (tr - tl) / 2;
            ll flag = (tm - tl + 1) & 1;
            apply(2 * v, tl, tm, lazy[v]);
            apply(2 * v + 1, tm + 1, tr, (flag ? -1 * lazy[v] : lazy[v]));
            lazy[v] = NO_UPDATE;
        }
    }

    void build(int v, int tl, int tr, const vector<ll>& a) {
        if (tl == tr) {
            tree[v] = Node(a[tl]);
        } else {
            int tm = tl + (tr - tl) / 2;
            build(2 * v, tl, tm, a);
            build(2 * v + 1, tm + 1, tr, a);
            tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
        }
    }

    void update(int v, int tl, int tr, int l, int r, ll val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            ll flag = (tl - l) & 1;
            apply(v, tl, tr, (flag ? -1 * val : val));
            return;
        }
        push(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, l, r, val);
        update(2 * v + 1, tm + 1, tr, l, r, val);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return Node(); // Returns neutral element
        if (l <= tl && tr <= r) return tree[v];
        
        push(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        return merge(query(2 * v, tl, tm, l, r), 
                     query(2 * v + 1, tm + 1, tr, l, r));
    }

    // --- PUBLIC API (0-indexed) ---
    void build(const vector<ll>& a) { build(1, 0, n - 1, a); }
    void update(int l, int r, ll val) { update(1, 0, n - 1, l, r, val); }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    ll query_val(int l, int r) { return query(1, 0, n - 1, l, r).val; }
};

void solve() {
    ll n, q; cin >> n >> q;

    LazySegTree st(n);

    while (q--) {
        char c; cin >> c;
        if(c == 'S') {
            ll l, r; cin >> l >> r;
            l--; r--;
            st.update(l, r, 1);
        }
        else if(c == 'P') {
            ll x; cin >> x;
            x--;
            cout << st.query(x, x).val << endl;
        } else {
            ll l, r; cin >> l >> r;
            l--; r--;
            cout << st.query(l, r).val << endl;
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