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

    vector<ll> b(n, 0);
    for (ll i = 0; i < n - 1; i++) b[i] = gcd(a[i], a[i + 1]);
    
    ll mx = *max_element(all(b)); ll ans = 0;
    ll idx = 0;
    while(idx < n - 1) {
        if(b[idx] != mx) idx++;
        ll sz = 0;
        while(b[idx] == mx) {sz++; idx++;}
        ans = max(ans, sz);
    }
    cout << mx << " " << ans + 1 << endl;
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