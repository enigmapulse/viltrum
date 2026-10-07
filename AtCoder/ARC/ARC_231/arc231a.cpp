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
    ll score = 0; ll curx = 0, cury = 0;
    for (ll i = 0; i < n; i++) {
        ll x, y, b; cin >> x >> y >> b;
        ll move = (curx - x) * (curx - x) + (cury - y) * (cury - y);
        if(move < b) {curx = x; cury = y;}
        score += min(move, b);
    }
    cout << score << endl;
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