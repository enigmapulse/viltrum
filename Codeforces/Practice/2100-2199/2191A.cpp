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
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++) v.push_back({a[i], i % 2});
    sort(all(v)); ll c = v[0].second;
    for (ll i = 1; i < n; i++) {
        if(v[i].second == c) {
            cout << "NO" << endl;
            return;
        }
        c = c ^ 1;
    }
    cout << "YES" << endl;
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