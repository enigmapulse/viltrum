#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;
using namespace __gnu_pbds;

// ordered set
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool multipleTests = false;

void solve() {
    ll x; cin >> x;
    ll i = 1;
    ordered_set<pair<ll, ll>> s; s.insert({x, i++});
    
    ll q; cin >> q;
    while(q--) {
        ll a, b; cin >> a >> b;
        s.insert({a, i++});
        s.insert({b, i++});
        ll n = s.size();
        auto median = *s.find_by_order(n / 2);
        cout << median.first << endl;
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