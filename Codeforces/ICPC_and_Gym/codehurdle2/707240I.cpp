#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e18;

using namespace std;

struct Node {
    ll val;
    Node() { val = -INF; } 
    Node(ll _val) { val = _val; }
};

struct LazySegTree {
    int n;
    vector<Node> tree;
    vector<ll> lazy;

    const ll NO_UPDATE = 0; 

    LazySegTree(int _n) {
        n = _n;
        tree.assign(4 * n, Node());
        lazy.assign(4 * n, NO_UPDATE);
    }

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.val = max(l.val, r.val); 
        return res;
    }

    void apply(int v, int tl, int tr, ll val) {
        tree[v].val += val;
        lazy[v] += val;
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] != NO_UPDATE) {
            int tm = tl + (tr - tl) / 2;
            apply(2 * v, tl, tm, lazy[v]);
            apply(2 * v + 1, tm + 1, tr, lazy[v]);
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
            apply(v, tl, tr, val);
            return;
        }
        push(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        update(2 * v, tl, tm, l, r, val);
        update(2 * v + 1, tm + 1, tr, l, r, val);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return Node(); 
        if (l <= tl && tr <= r) return tree[v];
        
        push(v, tl, tr);
        int tm = tl + (tr - tl) / 2;
        return merge(query(2 * v, tl, tm, l, r), 
                     query(2 * v + 1, tm + 1, tr, l, r));
    }

    void build(const vector<ll>& a) { build(1, 0, n - 1, a); }
    void update(int l, int r, ll val) { update(1, 0, n - 1, l, r, val); }
    Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
    ll query_val(int l, int r) { return query(1, 0, n - 1, l, r).val; }
};

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), w(n + 1); 
    inarr(a, n); inarr(w, n);

    // prev : idx of the last occurence of a[i]
    map<ll, ll> idx;
    vector<ll> prev(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        if(idx.count(a[i])) prev[i] = idx[a[i]];
        idx[a[i]] = i;
    }
    
    vector<vector<ll>> dp(k + 1, vector<ll> (n + 1, -INF));
    dp[0][0] = 0;

    for (ll cuts = 1; cuts <= k; cuts++) {
        // build the seg tree for cuts - 1
        LazySegTree tree(n + 1);
        tree.build(1, 0, n, dp[cuts - 1]);

        for (ll idx = 1; idx <= n; idx++) {
            ll j = prev[idx];
            ll k = prev[j];
            tree.update(j, idx - 1, w[idx]);
            if(j) tree.update(k, j - 1, -w[j]);
            dp[cuts][idx] = tree.query_val(0, idx - 1);
        }   
    }

    cout << dp[k][n] << endl;
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