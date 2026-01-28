#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, w; cin >> n >> w;
    vector<ll> c(n); inarr(c, n);

    vector<ll> cost(2*w, 0);
    for (ll i = 0; i < n; i++) {
        cost[(i + 1) % (2*w)] += c[i];
    }

    for(int i = 0; i < 2*w; i++) {
        cost.push_back(cost[i]);
    }

    for (ll i = 1; i < cost.size(); i++) cost[i] += cost[i - 1];
    
    ll ans = 4e18; 
    for (ll i = 0; i < 2*w; i++) {
        ll curr = cost[i + w - 1] - (i == 0 ? 0 : cost[i - 1]);
        ans = min(ans, curr);
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