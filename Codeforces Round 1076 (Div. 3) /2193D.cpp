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
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);
    sort(all(a));
    for (ll i = 1; i < n; i++) b[i] += b[i - 1];
    
    ll mx = 0;
    for (ll i = 0; i < n; i++) {
        ll diff = a[i];
        ll attacks = n - i;
        auto it = upper_bound(all(b), attacks);
        ll levels = 0;
        if(it != b.begin()) {
            levels = it - b.begin();
        }
        mx = max(mx, levels * diff);
    }
    
    cout << mx << endl;
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