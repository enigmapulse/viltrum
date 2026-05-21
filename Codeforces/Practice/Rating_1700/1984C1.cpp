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
    vector<ll> mn(n, 0), mx(n, 0);
    mn[0] = a[0]; mx[0] = abs(a[0]);

    vector<ll> c(n);
    for (ll i = 1; i < n; i++) {
        mn[i] = mn[i - 1] + a[i];
        mx[i] = max(abs(mx[i - 1] + a[i]), abs(mn[i - 1] + a[i]));
    }
    cout << mx[n - 1] << endl;
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