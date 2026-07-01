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
    for (ll i = 0; i < n - 2; i++) {
        string cur = s.substr(i, 3);
        if(cur == "pie" || cur == "map") cnt++;
    }
    for (ll i = 0; i < n - 4; i++) {
        string cur = s.substr(i, 5);
        if(cur == "mapie") cnt--;
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