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

    bool chk = false;
    for (ll i = 1; i * i <= n; i++) {
        // i is the number of rows
        if(n % i != 0) continue;

        // mx is the max offset we could have from the next row
        ll mx = n / i;

        // for all possible offsets check if
        // the value at 90 degrees is same
        for (ll j = 1; j <= mx; j++) {
            if(j % i != 0) continue;
            if((i + (j / i) * j) % n == 0) chk |= true;
        }
    }
    
    if(chk) cout << "Yes" << endl;
    else cout << "No" << endl;
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