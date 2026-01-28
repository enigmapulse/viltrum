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
    ll m[n + 1][n + 1];
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= i; j++) {
            cin >> m[i][j];
        }
    }
    
    ll curr = 1;
    for (ll i = 1; i <= n; i++) {
        if(curr >= i) curr = m[curr][i];
        else curr = m[i][curr];
    }
    cout << curr << endl;
    
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