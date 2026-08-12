#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    vector<ll> v = {a, b, c}; sort(all(v));
    ll x = v[0];
    ll y = v[1];
    ll z = v[2];
    ll mn = z - x;
    mn = min(mn, z);
    mn = min(mn, y);
    cout << mn << endl;
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