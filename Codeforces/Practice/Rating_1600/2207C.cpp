#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, h; cin >> n >> h;
    vector<ll> a(n); inarr(a, n);

    ll best1 = 0; ll idx = -1;
    vector<ll> chosen_mx;

    // the best first choice
    for (ll i = 0; i < n; i++) {
        vector<ll> mx(n, 0); mx[i] = a[i];
        for (ll j = i + 1; j < n; j++) mx[j] = max(mx[j - 1], a[j]);
        for (ll j = i - 1; j >= 0; j--) mx[j] = max(mx[j + 1], a[j]);
        if (best1 <= h * n - accumulate(all(mx), 0ll)) {
            idx = i;
            best1 = h * n - accumulate(all(mx), 0ll);
            chosen_mx = mx;
        }
    }

    // cerr << "best1 : " << best1 << endl;
    // cerr << "idx : " << idx << endl;

    ll best2 = 0;

    // the second best choice
    for (ll i = 0; i < n; i++) {
        vector<ll> mx(n, 0); mx[i] = a[i];
        for (ll j = i + 1; j < n; j++) mx[j] = max(mx[j - 1], a[j]);
        for (ll j = i - 1; j >= 0; j--) mx[j] = max(mx[j + 1], a[j]);
        ll curr = 0;
        for (ll j = 0; j < n; j++) curr += max(chosen_mx[j] - mx[j], 0ll);
        if(best2 <= curr) {
            best2 = curr; idx = i;
        }
    }
    // cerr << "best2 : " << best2 << endl;
    // cerr << "idx : " << idx << endl;

    cout << best1 + best2 << endl;
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