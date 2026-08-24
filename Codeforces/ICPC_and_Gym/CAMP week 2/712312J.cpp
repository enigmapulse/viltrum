#include <bits/stdc++.h>
#include <functional>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp;
    vector<ll> pre(n), suff(n);
    for (ll i = 0; i < n; i++) {
        mp[a[i]]++;
        pre[i] = mp[a[i]];
    }
    mp.clear();
    for (ll i = n - 1; i >= 0; i--) {
        mp[a[i]]++;
        suff[i] = mp[a[i]];
    }
    
    ll ans = 0; ll t = 0;
    ordered_set<pll> st; st.insert({pre[0], t++});
    for (ll i = 1; i < n; i++) {
        ll val = suff[i];
        // i wanna find the values which are strictly greater than val in the ordered set
        ans += st.order_of_key({val, n});
        st.insert({pre[i], t++});
    }
    cout << ans << endl;
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