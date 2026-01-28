#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;
    ll n = s.size(); ll cnt = 0;

    for (ll i = 0; i < n; i++) {
        if(s[i] != t[i]) {++cnt;}
    }

    cout << cnt << endl;

    string curr = s;
    for (ll i = 0; i < n; i++) {
        if(curr[i] > t[i]) {
            curr[i] = t[i];
        cout << curr << endl;

        } 
    }

    for (ll i = n - 1; i >= 0; i--) {
        if(curr[i] < t[i]) {
            curr[i] = t[i];
        cout << curr << endl;

        } 
    }
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