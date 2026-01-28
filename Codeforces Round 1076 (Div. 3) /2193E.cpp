#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e12;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; vector<ll> a(n); inarr(a, n);
    vector<ll> ans(n + 1, INF);
    sort(all(a));
    for (ll i = 0; i < n; i++) ans[a[i]] = 1;
    
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j * j <= i; j++) {
            if(i % j != 0) continue;
            ll div1 = j, div2 = i / j;
            if(ans[div1] != INF && ans[div2] != INF) {
                ans[i] = min(ans[div1] + ans[div2], ans[i]);
            }
        }
    }
    
    for (ll i = 1; i <= n; i++) {
        if(ans[i] == INF) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    
    cout << endl;
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