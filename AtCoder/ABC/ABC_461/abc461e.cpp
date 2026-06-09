#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;
using namespace __gnu_pbds;

bool multipleTests = false;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    ll n, q; cin >> n >> q;

    ll tot = 0;
    ordered_set<ll> row, col;
    while(q--) {
        ll ops, x; cin >> ops >> x;
        if(ops == 1) {
            ll prev = a[x].size();
            if(prev == 0) tot += n;
            else tot += prev - 1;
            a[x].insert(-1);
            cout << tot << endl;
        }
        else {

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