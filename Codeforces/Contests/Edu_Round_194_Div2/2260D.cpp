#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    bool pos = false;
    for (ll i = 0; i < n - 1; i++) {
        if(s[i] == '0' && s[i + 1] == '0') {
            pos = true;
        }
    }
    if(pos || s[0] == '0') {
        cout << -1 << endl;
        return;
    }

    ll idx = 0; ll ans = 0;
    while (idx < n) {
        ll last = idx;
        while(last < n && s[last] != '0') last++;
        ll curr = (s[idx] == '+') ? 1 : -1;
        ll mn1 = abs(curr);
        for (ll i = idx + 1; i < last; i++) {
            ll prev = curr;
            if(s[i] == s[i - 1]) {
                if (curr > 0) curr = 3 - curr;
                else curr = -3 - curr;
            }
            else {
                if(curr > 0) curr = -1;
                else curr = 1;
            }
            mn1 = max(mn1, abs(curr - prev));
        }
        if (last < n) mn1 = max(mn1, abs(curr));

        curr = (s[idx] == '+') ? 2 : -2;
        ll mn2 = abs(curr);
        for (ll i = idx + 1; i < last; i++) {
            ll prev = curr;
            if(s[i] == s[i - 1]) {
                if (curr > 0) curr = 3 - curr;
                else curr = -3 - curr;
            }
            else {
                if(curr > 0) curr = -1;
                else curr = 1;
            }
            mn2 = max(mn2, abs(curr - prev));
        }
        if (last < n) mn2 = max(mn2, abs(curr));
        
        ans = max(ans, min(mn1, mn2));
        idx = last + 1;
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