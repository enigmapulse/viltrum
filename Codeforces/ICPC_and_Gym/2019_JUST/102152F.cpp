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
    if(!(s[0] >= 'a' && s[0] <= 'z')) {
        cout << "NO" << endl;
        return;
    }

    ll cnt = 0;
    for (ll i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') cnt++;
    }
    
    if(cnt <= 6) cout << "YES" << endl;
    else cout << "NO" << endl;
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