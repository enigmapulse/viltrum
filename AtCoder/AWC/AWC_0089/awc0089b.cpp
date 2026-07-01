#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, d, k, c; cin >> n >> d >> k >> c;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        ll v, s; cin >> v >> s;
        if(s == 0) a[i] = v;
        else a[i] = max(v - c, 0ll);
    }
    sort(all(a), greater());

    ll mx = 0, sm = 0;
    for (ll i = 0; i < n; i++) {
        sm += a[i];
        mx = max(mx, sm - i * k);
    }
    if(mx >= d) cout << mx << endl;
    else cout << -1 << endl;
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