#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string a, b, c; cin >> a >> b >> c;

    string x, y, z; ll n = a.size(), cnt = n;
    for (ll i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] == c[i]) {
            cnt--;
            x += a[i]; y += b[i]; z += c[i];
        }
    }
    if(cnt > 3) {cout << "Impossible" << endl; return;}
    if(cnt < 2) {cout << "Ambiguous" << endl; return;}

    for (ll i = 0; i < (1 << cnt); i++) {
        for (ll j = 0; j < (1 << cnt); j++) {
            for (ll k = 0; k < (1 << cnt); k++) {
                for (ll idx = 0; idx < cnt; idx++) {
                    ll shift = (1 - idx);
                    
                }
            }
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