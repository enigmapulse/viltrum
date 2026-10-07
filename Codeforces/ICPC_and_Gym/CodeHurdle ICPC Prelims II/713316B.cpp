#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    ll n; cin >> n;
    vector<ll> p(n + 1); inarr(p, n);

    // counts how many elements bigger than some value
    // are there to the left of it
    map<ll, ll> cnt, cnt1;
    ordered_set<ll> s;
    for (ll i = n; i >= 1; i--) {
        if(s.empty()) {
            cnt[p[i]] = 0;
            s.insert(p[i]);
            continue;
        }
        cnt[p[i]] = s.size() - s.order_of_key(p[i]);
        cnt1[p[i]] = s.order_of_key(p[i]);
        s.insert(p[i]);
    }

    // for(auto [x, val] : cnt) cout << val <<  " ";

    SegTree st(n + 1);
    vector<ll> a(n + 1);
    a[p[n]] = cnt[p[n]]; a[p[n - 1]] = cnt[p[n - 1]];
    st.build(a, 1, 1, n);

    SegTree st1(n + 1);
    vector<ll> a1(n + 1);
    a1[p[n]] = cnt1[p[n]]; a1[p[n - 1]] = cnt1[p[n - 1]];
    st1.build(a1, 1, 1, n);

    vector<ll> ans(n + 1, 0);
    for (ll i = n - 2; i >= 1; i--) {
        // cerr << p[i] << " ";
        if(p[i] != n) ans[p[i]] = st.sum(1, 1, n, p[i] + 1, n);
        if(p[i] != 1) ans[p[i]] += st1.sum(1, 1, n, 1, p[i] - 1);
        st.update(1, 1, n, p[i], cnt[p[i]]);
        st1.update(1, 1, n, p[i], cnt1[p[i]]);
    }

    cout << accumulate(all(ans), 0ll) << endl;
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