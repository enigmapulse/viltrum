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
    string s; cin >> s;

    s += s;
    bool chk = true;
    for (ll i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) chk = false;
    }
    if(chk) {
        cout << -1 << endl;
        return;
    }
    
    ll start = 0;

    ll ans = 0;
    ll len = 1;
    for (ll i = 1; i < s.size(); i++) {
        if (s[start + i] != s[start + i - 1]) {
            len++;
        } else {
            ans = max(ans, (len + 1) / 2);
            len = 1;
        }
    }
    ans = max(ans, (len + 1) / 2);
    
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