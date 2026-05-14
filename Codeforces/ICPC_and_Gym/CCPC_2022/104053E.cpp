#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definition for an ordered set
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> ans(n, 0);
    vector<pll> a; 
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        a.push_back({x, i});
    }
    sort(all(a));
    ll res[n];

    ordered_set<ll> s;

    ll sum  = 0;
    for(ll i = 0;i<n;i++){
        if(i==0){
            res[a[0].second] = 0;
            s.insert(a[0].second);
            sum+=a[i].first;
            continue;
        }
        ll need = a[i].first*i - sum + s.order_of_key(a[i].second);
        s.insert(a[i].second);
        sum+=a[i].first;
        if(need>=m - 1){
            res[a[i].second] = -1;
        }
        else res[a[i].second] = need;
    }
    
    for(auto x:res) cout<<x<<endl;
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