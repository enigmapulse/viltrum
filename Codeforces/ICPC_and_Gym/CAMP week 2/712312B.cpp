#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MAXN = 2e5 + 5;
const ll block = 300;

using namespace std;

bool multipleTests = false;
ll m[block][block] = {};
ll c[block][block] = {};

void solve() {
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        ll x1, x2, y1, a, b, y2;
        cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        ll q = i / block, r = i % block;
        m[q][r]
    }
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