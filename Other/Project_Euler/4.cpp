#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

bool isPal(ll n) {
    bool res = true;
    string s = to_string(n);
    for (ll i = 0; i < s.size(); i++) res &= (s[i] == s[s.size() - 1 - i]); 
    return res;
}

void solve() {
    ll ans = 0;
    for (ll i = 100; i < 1000; i++) {
        for (ll j = 100; j < 1000; j++) {
            ll num = i * j;
            if(isPal(num)) ans = max(ans, num);
        }
    }
    cout << ans << endl;
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