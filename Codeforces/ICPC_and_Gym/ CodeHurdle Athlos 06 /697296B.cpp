#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

struct node {
    bool start = false, end = false;
    ll cnt = 0;
};

struct SegTree {
    ll n; vector<node> t;
    SegTree(ll _n) { n = _n; t.assign(4 * n, node()); }

    node merge(node& a, node& b) {
        node res;
        res.cnt = a.cnt + b.cnt - (a.end && b.start);
        res.start = a.start;
        res.end = b.end;
        return res;
    }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = {a[tl] == 1, a[tl] == 1, a[tl]};
        }
        else {
            ll tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            t[v] = {new_val == 1, new_val == 1, new_val};
        }
        else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }
};

void solve() {
    ll n, q, k; cin >> n >> q >> k;
    vector<ll> a(n); inarr(a, n);

    vector<ll> base(n);
    for (ll i = 0; i < n; i++) {
        base[i] = (__builtin_popcountll(a[i]) >= k);
    }
    
    SegTree st(n); st.build(base, 1, 0, n - 1);

    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll pos, x; cin >> pos >> x;
            a[pos - 1] |= x;
            ll nval = (__builtin_popcountll(a[pos - 1]) >= k);
            if(base[pos - 1] != nval) {
                base[pos - 1] = nval;
                st.update(1, 0, n - 1, pos - 1, nval);
            }
        }
        else if(ops == 2) {
            ll pos, x; cin >> pos >> x;
            a[pos - 1] ^= x;
            ll nval = (__builtin_popcountll(a[pos - 1]) >= k);
            if(base[pos - 1] != nval) {
                base[pos - 1] = nval;
                st.update(1, 0, n - 1, pos - 1, nval);
            }
        }
        else {
            cout << st.t[1].cnt << endl;
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