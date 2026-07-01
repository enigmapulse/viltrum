#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1); inarr(a, n);
    vector<pll> b(m);
    for (ll i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    

    ll ans = 0;
    vector<ll> perm(n + 1); iota(all(perm), 0);
    auto chk = [&] () {
        for (ll i = 0; i < m; i++) {
            ll u = b[i].first, v = b[i].second;
            if(perm[u] > perm[v]) return false;
        }
        return true;
    };

    auto f = [&] () {
        ll score = 0;
        for (ll i = 1; i <= n; i++) {
            score += perm[i] * a[i];
        }
        return score;
    };

    do {
        if(chk()) ans = max(ans, f());
    } while(next_permutation(perm.begin() + 1,  perm.end()));
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