#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;

    ordered_set<pll> s; vector<ll> a(n, 0);
    for (ll i = 0; i < n; i++) {
        s.insert({0, i});
    }
    
    ll shift = 0;
    while(q--) {
        ll ops, x; cin >> ops >> x;
        if(ops == 1) {
            x--;
            auto it = s.find({a[x], x});
            s.erase(it);
            s.insert({a[x] + 1, x});
            a[x]++;
            auto ut = s.lower_bound({1 + shift, -1});
            if(ut == s.begin()) shift++;
        }
        else {
            auto it = s.lower_bound({x + shift, - 1});
            if(it == s.end()) cout << 0 << endl;
            else cout << n - s.order_of_key(*it) << endl;
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