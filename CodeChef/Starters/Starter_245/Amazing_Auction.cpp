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
    vector<ll> a(n), c(n); inarr(a, n); inarr(c, n);

    ll best = 0;
    for (ll i = 0; i < n; i++) {
        vector<ll> reward(n, 0);
        for (ll j = 0; j < n; j++) {
            reward[j] = (a[i] - max(a[i] - a[j], 0ll) * c[j]);
        }
        sort(all(reward), greater());
        ll curr = 0;
        for (ll j = 0; j <= k; j++) curr += reward[j];
        best = max(best, curr - a[i]);
    }
    cout << best << endl;
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