#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, c; cin >> n >> c;
    vector<ll> a(n); inarr(a, n);

    sort(all(a)); ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] < c) {
            if(i >= (n / 2)) ans += a[i] - c;
        } 
        else ans += a[i] - c;
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