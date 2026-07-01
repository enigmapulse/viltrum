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
    vector<ll> a(n); inarr(a, n);
    for (ll i = 0; i < n - 2; i++) {
        if(a[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
        a[i] = 0;
    }
    if(a[n - 2] != 0 || a[n - 1] != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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