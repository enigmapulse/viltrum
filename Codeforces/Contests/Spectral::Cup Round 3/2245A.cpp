#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

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

#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (ll _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
using namespace std;

bool multipleTests = true;

struct SegTree {
    ll n; vector<ll> t;
    SegTree(ll _n) { n = _n; t.assign(4 * n, 0); }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            ll tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    ll sum(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        ll tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
             + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) t[v] = new_val;
        else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    invec(a);

    SegTree st(n);
    st.build(a, 1, 0, n-1);

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll pos, val;
            cin >> pos >> val;
            st.update(1, 0, n-1, pos, val);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << st.sum(1, 0, n-1, l, r) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T = 1;
    if (multipleTests) cin >> T;
    while (T--) solve();
    return 0;
}

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    if(n < 2 * k) {
        cout << -1 << endl;
        return;
    }

    ll cnt = 0;
    for (ll i = 0; i < k; i++) cnt += (s[i] == 'L');
    for (ll i = 0; i < k; i++) cnt += (s[n - 1 - i] == 'R');
    cout << cnt << endl;
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