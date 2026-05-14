#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<vector<pll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vector<ll> d(n + 1);
    set<ll> odd, even;
    function<void(ll, ll, ll, ll)> dfs = [&] (ll v, ll p, ll curr, ll par) {
        d[v] = curr;
        if(par) odd.insert(v);
        else even.insert(v);
        for(auto [c, w] : adj[v]) {
            if(c == p) continue;
            dfs(c, v, curr ^ w, par ^ 1);
        }
    };
    dfs(1, 0, 0, 0);
    ll sz0 = even.size();
    ll sz1 = odd.size();

    vector<ll> cnt0(30), cnt1(30);
    for (ll v : even) {
    for (ll j = 0; j < 30; j++) {
            cnt0[j] += (d[v] >> j) & 1;
        }
    }
    for (ll v : odd) {
        for (ll j = 0; j < 30; j++) {
            cnt1[j] += (d[v] >> j) & 1;
        }
    }

    auto sum = [&] (ll offset, ll par) {
        auto& cnt = (par == 0 ? cnt0 : cnt1);
        ll sz = (par == 0 ? sz0 : sz1);
        ll sm = 0;
        for (ll i = 0; i < 30; i++) {
            if((offset >> i) & 1) sm += (sz - cnt[i]) * (1LL << i);
            else sm += cnt[i] * (1LL << i);
        }
        return sm;
    };
    
    ll offset = 0;
    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll x; cin >> x;
            offset ^= x;
        }
        else {
            ll s; cin >> s;
            ll ans = 0;
            if(odd.find(s) != odd.end()) ans = sum(d[s], 1) + sum(d[s] ^ offset, 0);
            else ans = sum(d[s], 0) + sum(d[s] ^ offset, 1);
            cout << ans << endl;
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