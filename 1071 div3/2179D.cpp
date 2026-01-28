#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n;  cin >> n;
    cout << (1LL << n) - 1 << " ";

    for (int k = n - 1; k >= 0; --k) {
        ll suff = (1LL << k) - 1;
        ll lim = (1LL << (n - 1 - k));
        for (ll j = 0; j < lim; ++j) {
            ll val = (j << (k + 1)) | suff;
            cout << val << " ";
        }
    }

    cout << endl;
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