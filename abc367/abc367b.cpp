#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s; cin >> s;
    ll n = s.size();
    ll last = 0;
    if(s[n - 1] == '0' && s[n - 2] == '0' && s[n - 3] == '0') last = 3;
    else if(s[n - 1] == '0' && s[n - 2] == '0') last = 2;
    else if(s[n - 1] == '0') last = 1;

    for (ll i = 0; i < n; i++) {
        if(s[i] == '.') break;
        else cout << s[i];
    }
    
    if(last == 3) return;
    if(last == 2) {
        cout << '.';
        cout << s[n - 3];
    }
    if(last == 1) cout << '.' << s[n - 3] << s[n - 2];
    if(last == 0) cout << '.' << s[n - 3] << s[n - 2] << s[n - 1];
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