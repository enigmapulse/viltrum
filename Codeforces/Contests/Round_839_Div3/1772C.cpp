#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll k, n; cin >> k >> n;

    ll x = 0;
    while ((x + 1) * x / 2 + k - x <= n) x++;
    x--;
    x = min(x, k - 1);

    vector<ll> ans; ans.push_back(1);
    for (ll i = 1; i <= x; i++) {
        ans.push_back(ans.back() + i);
    }
    for (ll i = x + 1; i < k; i++) {
        ans.push_back(ans.back() + 1);
    }

    for (auto v : ans) cout << v << " ";
    cout << endl;
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