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
    string s, t; cin >> s >> t;

    ll ct_odd = 0, ct_even = 0;
    for (ll i = 0; i < n; i++) {
        if(i & 1 && s[i] == '1') ct_odd++;
        if(i % 2 == 0 && s[i] == '1') ct_even++;
        if(i & 1 && t[i] == '1') ct_odd--;
        if(i % 2 == 0 && t[i] == '1') ct_even--;
    }
    if(ct_odd == 0 && ct_even == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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