#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        bool chk = true;
        if(i - 1 >= 0 && s[i - 1] == 'o') chk = false;
        if(i + 1 <= n - 1 && s[i + 1] == 'o') chk = false;
        if(chk && s[i] == 'x') cnt++;
    }
    cout << cnt << endl;
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