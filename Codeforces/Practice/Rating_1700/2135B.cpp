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
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    ll mx1 = -1e15, mx2 = -1e15;
    for (ll i = 0; i < n; i++) {
        mx1 = max(mx1, x[i] + y[i]);
        mx2 = max(mx2, y[i] - x[i]);
    }
    ll sum, diff;
    ll res;
    cout << "? R 1000000000" << endl << flush;
    cin >> res;
    cout << "? R 1000000000" << endl << flush;
    cin >> res;
    cout << "? U 1000000000" << endl << flush;
    cin >> res;
    cout << "? U 1000000000" << endl << flush;
    cin >> res;
    sum = res + mx1 - 4e9;

    cout << "? L 1000000000" << endl << flush;
    cin >> res;
    cout << "? L 1000000000" << endl << flush;
    cin >> res;
    cout << "? L 1000000000" << endl << flush;
    cin >> res;
    cout << "? L 1000000000" << endl << flush;
    cin >> res;
    diff = res + mx2 - 4e9;

    cout << "! " << (sum - diff) / 2 << " " << (sum + diff) / 2 << endl << flush;
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