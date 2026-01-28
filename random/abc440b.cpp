#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> val;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        val.push_back({x, i + 1});
    }
    sort(all(val));
    cout << val[0].second << " ";
    cout << val[1].second << " ";
    cout << val[2].second << endl;
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