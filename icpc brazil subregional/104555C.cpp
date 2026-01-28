#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, x, n) for (int _i = x; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n + 1, 0); p[1] = 1; inarr(p, 2, n + 1);
    vector<ll> v(n + 1, 0); inarr(v, 1, n + 1);

    vector<vector<ll>> child(n + 1);
    for (ll i = 2; i <= n; i++) {
        child[p[i]].push_back(i);
    }

    vector<ll> ans(n + 1, 0); ans[1] = 1;
    vector<ll> tails; map<ll, ll> rem;

    auto add = [&] (ll y) {
        ll x = v[y];
        if(tails.empty() || tails.back() < x) {
            tails.push_back(x);
            rem[y] = -1;
        }
        else {
            auto it = lower_bound(all(tails), x);
            rem[y] = *it;
            *it = x;
        }
    };

    auto del = [&] (ll x) {
        ll y = v[x];
        ll val = rem[x];
        if(val == -1) tails.pop_back();
        else {
            auto it = lower_bound(all(tails), y);
            *it = val;
        }
    };

    function <void(ll, ll)> dfs = [&] (ll v, ll p) {
        add(v); ans[v] = tails.size();
        for(auto u : child[v]) {
            dfs(u, v);
        }
        del(v);
    };

    dfs(1, 1);

    for (ll i = 2; i <= n; i++) cout << ans[i] << " \n"[i == n];
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