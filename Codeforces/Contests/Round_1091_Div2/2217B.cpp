#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> b(n); inarr(b, n);
    ll x; cin >> x;

    ll cnt1 = 0, cnt2 = 0;
    for (ll i = x - 1; i < n - 1; i++) {
        if(b[i] != b[i + 1]) cnt1++;
    }
    
    for (ll i = x - 1; i > 0; i--) {
        if(b[i] != b[i - 1]) cnt2++;
    }
    
    ll ans = max(cnt1, cnt2);
    if(ans & 1) cout << ans + 1 << endl;
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