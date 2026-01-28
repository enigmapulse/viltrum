#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<ll, ll>,
    null_type,
    less<pair<ll, ll>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll ans = 0;

    vector<ll> pre(n, 0);
    ordered_set freq;
    ll idx = 0; freq.insert({0, idx++});

    for(ll i = 0; i < n; ++i) {
        char ch = s[i];
        if(ch == 'A') pre[i] = 1;
        else if(ch == 'B') pre[i] = -1;

        if (i != 0) pre[i] += pre[i - 1];

        ans += freq.order_of_key({pre[i], 0});
        freq.insert({pre[i], idx++});
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