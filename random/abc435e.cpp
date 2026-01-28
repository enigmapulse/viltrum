#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

struct Node {
    ll lazy;
    ll ans;        
    bool pending;  
    ll tl, tr;
    
    Node() {
        lazy = 0; ans = 0; pending = false;
        tl = 1; tr = 0;
    }
};

struct segtree {
    ll n; vector<Node> t;

    segtree(ll _n) {
        n = _n;
        t.assign(4*n, Node());
    }

    Node merge(Node l, Node r) {
        if (l.tl > l.tr) return r; 
        if (r.tl > r.tr) return l; 

        Node p;
        p.tl = l.tl; p.tr = r.tr;
        p.ans = l.ans + r.ans; 
        p.lazy = 0;
        p.pending = false;
        return p;
    }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        if(tl == tr) {
            t[v].tl = tl; t[v].tr = tr;
            t[v].ans = a[tl];
        }
        else {
            ll tm = (tl + tr)/2;
            build(a, 2*v, tl, tm);
            build(a, 2*v + 1, tm + 1, tr);
            t[v] = merge(t[2*v], t[2*v + 1]);
        }
    }

    void push(ll v, ll tl, ll tr) {
        if(t[v].pending) {
            ll tm = (tl + tr) / 2;
            
            t[v].ans = t[v].lazy * (tr - tl + 1);
            if(tl != tr) {
                t[2*v].lazy = t[v].lazy;
                t[2*v].pending = true;
                
                t[2*v + 1].lazy = t[v].lazy;
                t[2*v + 1].pending = true;
            }
            
            t[v].lazy = 0;
            t[v].pending = false; 
        }
    }

    void range_update(ll v, ll tl, ll tr, ll lo, ll hi, ll val) {
        push(v, tl, tr); 
        if(lo > hi) return;
        
        if(tl == lo && tr == hi) {
            t[v].lazy = val;
            t[v].pending = true; 
            push(v, tl, tr);   
        }
        else {
            ll tm = (tl + tr)/2;
            range_update(2*v, tl, tm, lo, min(tm, hi), val);
            range_update(2*v + 1, tm + 1, tr, max(tm + 1, lo), hi, val);
            t[v] = merge(t[2*v], t[2*v + 1]);
        }
    }

    Node query(ll v, ll tl, ll tr, ll lo, ll hi) {
        push(v, tl, tr); 
        if(lo > hi) return Node();
        
        if(tl == lo && tr == hi) return t[v];
        else {
            ll tm = (tl + tr)/2;
            Node x = query(2*v, tl, tm, lo, min(hi, tm));
            Node y = query(2*v + 1, tm + 1, tr, max(lo, tm + 1), hi);
            return merge(x, y);
        }
    }
};

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n, 1); 
    segtree st(n); st.build(a, 1, 0, n - 1);

    while(q--) {
        ll l, r; cin >> l >> r;
        st.range_update(1, 0, n - 1, l - 1, r - 1, 0);
        Node result = st.query(1, 0, n - 1, 0, n - 1);
        cout << result.ans << endl;
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