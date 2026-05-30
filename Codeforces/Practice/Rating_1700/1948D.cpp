#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s; 
    ll n = s.size();

    ll ans = 0;
    for (ll len = 1; len <= n; len++) {
        ll curr = 0;
        for (ll i = 0; i + len < n; i++) {
            if(s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?') curr += 2;
            else curr = 0;
            if(curr == 2 * len) {
                ans = max(curr, ans);
                break;
            }
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