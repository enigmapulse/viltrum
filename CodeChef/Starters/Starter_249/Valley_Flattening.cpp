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

    vector<pair<ll, ll>> b;
    for (ll i = 0; i < n; i++) {
        b.push_back({a[i], i});
    }
    sort(all(b), greater());

    for(auto [_, idx] : b) {
        if(idx == 0 || idx == n - 1) continue;
        if(a[idx] < min(a[idx - 1], a[idx + 1])) {
            a[idx - 1] = a[idx];
            a[idx + 1] = a[idx];
        }
    }
    cout << accumulate(all(a), 0ll) << endl;
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