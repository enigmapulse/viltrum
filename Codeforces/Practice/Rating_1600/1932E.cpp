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

    vector<ll> pre(n, 0);
    for (ll i = 0; i < n; i++) {
        pre[i] = (s[i] - '0');
        if(i > 0) pre[i] += pre[i - 1];
    }
    
    string ans; ll carry = 0;
    for (ll i = n - 1; i >= 0; i--) {
        carry += pre[i];
        ans += (carry % 10) + '0';
        carry /= 10;
    }

    while (carry) {
        ans += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(all(ans));

    ll pos = 0;
    while(pos + 1 < s.size() && ans[pos] == '0') ++pos;
    ans = ans.substr(pos);
    
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