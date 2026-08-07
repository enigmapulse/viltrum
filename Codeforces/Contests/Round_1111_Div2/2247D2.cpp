#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e13;

using namespace std;

bool multipleTests = true;

struct node {
    ll mn = INF, mx = 0;
    node() {}
    node(ll num) {
        mn = num; mx = num;
    }
    node(ll _mn, ll _mx) {
        mn = _mn; mx = _mx;
    }
};

struct segtree {

    ll n; vector<node> t;
    segtree(ll _n) {
        n = _n;
        t.assign(4 * n, node());
    }

    node merge(node left, node right) {
        return node(
            min(left.mn, right.mn),
            max(left.mx, right.mx)
        );
    }

    void build(vector<ll>& a, ll v, ll tl, ll tr) {
        if(tl == tr) {
            t[v] = node(a[tl]);
            return;
        }
        ll tm = tl + (tr - tl)/2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void update(ll v, ll tl, ll tr, ll idx, ll nval) {
        if(tl == tr) {
            t[v] = node(nval);
            return;
        }
        ll tm = tl + (tr - tl)/2;
        if(idx <= tm) update(2 * v, tl, tm, idx, nval);
        else update(2 * v + 1, tm + 1, tr, idx, nval);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    node query(ll v, ll tl, ll tr, ll left, ll right) {
        if(tr > tl) return node();
        if(tl == tr) return t[v];
        ll tm = tl + (tr - tl)/2;
        return merge(
            query(2 * v, tl, tm, left, min(right, tm)),
            query(2 * v + 1, tm + 1, tr, max(left, tm + 1), right)
        );
    }

    
};

void solve() {
    
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