#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n = 16;

    vector<ll> p = {15, 7, 3, 11, 1, 5, 9, 13, 0, 2, 4, 6, 8, 10, 12, 14 };
    // vector<ll> p = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    ll val = p[0];
    ll ans = __builtin_popcountll(val);

    for (ll i = 1; i < n; i++) {
        val &= p[i];
        int cnt = __builtin_popcountll(val);   // x is long long
        ans += cnt;
    }


    // Output result
    cout << "Max ans = " << ans << '\n';
    cout << "Lexicographically smallest permutation:\n";
    for (ll x : p) cout << x << " ";
    cout << '\n';
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
