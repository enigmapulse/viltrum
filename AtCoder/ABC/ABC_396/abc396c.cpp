#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> b(n), w(m); 
    inarr(b, n); inarr(w, m);

    sort(all(w), greater());
    for (ll i = 1; i < m; i++) {
        w[i] += w[i - 1];
    }

    sort(all(b), greater());
    for (ll i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }
    for (ll i = n - 2; i >= 0; i--) {
        b[i] = max(b[i], b[i + 1]);
    }
    
    ll ans = 0;
    for (ll i = 0; i < min(n, m); i++) {
        ans = max(ans, b[i] + w[i]);
    }
    cout << max(ans, b[0]) << endl;
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