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
    if(n < 3) cout << -1 << endl;
    else {
        for (ll i = 0; i < n; i++) {
            if(i == 0) {
                for (ll i = 0; i < n; i++) cout << 1 << " ";
            }
            else if(i == 1 || i == 2) {
                for (ll i = 0; i < n; i++) {
                    if(i != n - 1 && i != n - 2) cout << 0 << " ";
                    else cout << 1 << " ";
                }
            }
            else {
                for (ll i = 0; i < n; i++) {
                    if(i == n - 1) cout << 1 << " ";
                    else cout << 0 << " ";
                }
            }
            cout << endl;
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