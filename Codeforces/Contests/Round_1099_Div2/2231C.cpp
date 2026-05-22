#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

bool multipleTests = true;

ll nxt(ll x) {
    if(x & 1) return x + 1;
    else return x / 2;
}

pll lca (ll x, ll y, ll wx, ll wy) {
    if(x > y) {swap(x, y); swap(wx, wy);}
    if(x == y) return {x, 0};
    else if(y == x + 1 && (x & 1)) return {y, wx};
    else {
        auto [u, v] = lca(x, nxt(y), wx, wy);
        return {u, v + wy};
    }
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    ll cnt1 = count(all(a), 1);
    auto [meet, cost] = lca(a[0], a[1], 1, 1);
    for (ll i = 2; i < n; i++) {
        auto [nmeet, ncost] = lca(meet, a[i], i, 1);
        meet = nmeet; cost += ncost;
    }
    
    if(meet == 2) cout << min(cost + n - 2 * cnt1, cost) << endl;
    else cout << cost << endl;
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