#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    
    ll mn = n; string ans;
    for (ll i = 0; i <= k; i++) {
        string b(n, '0');
        ll cnt = i;
        for (ll j = 0; j < n; j++) {
            if(cnt && s[j] == '(') {b[j] = '1'; cnt--;}
        }
        cnt = k - i;
        for (ll j = n - 1; j >= 0; j--) {
            if(cnt && s[j] == ')') {b[j] = '1'; cnt--;}
        }
        string ns;
        for (ll i = 0; i < n; i++) {
            if(b[i] == '0') ns += s[i];
        }
        ll bal = 0, pairs = 0;
        for(auto x : ns) {
            if(x == '(') bal++;
            else if(bal) {bal--; pairs++;}
        }
        if(pairs < mn) {
            mn = pairs; ans = b;
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