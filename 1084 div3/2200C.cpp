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
    for (ll j = 0; j < n; j++) {
        string t;

        for (ll i = 0; i < s.size(); i++) {
            if(s[i] != s[i + 1]) t += s[i];
            else i++;
        }

        if(t.empty()) {
            cout << "YES" << endl;
            return;
        }

        s = t;
    }

    cout << "NO" << endl;
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