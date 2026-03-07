#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; 
    vector<ll> a(n); inarr(a, n);
    ll mx = *max_element(all(a)), mn = *min_element(all(a));
    ll ans = 1e12;

    vector<ll> b = a; sort(all(b));
    for (ll i = 0; i < n; i++) {
        if(a[i] != b[i]) ans = min(ans, max(mx - a[i], a[i] - mn));
    }
    
    if (ans == 1e12) cout << -1 << endl;
    else cout << ans << endl;
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