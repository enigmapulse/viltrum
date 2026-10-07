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
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) cnt++;
    }

    s.erase(unique(all(s)), s.end());
    if(s.size() == 1 || s.size() == 2) cout << cnt << endl;
    else if (s.size() == 3) cout << cnt + 1 << endl;
    else cout << cnt + 2 << endl;
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