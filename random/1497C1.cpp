#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    if(n & 1) cout << (n - 1)/2 << " "<< (n - 1)/2 << " " << 1 << endl;
    else {
        if(n % 4 == 0) cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
        else cout << n/2 - 1 << " " << n / 2 -  1 << " " << 2 << endl;
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