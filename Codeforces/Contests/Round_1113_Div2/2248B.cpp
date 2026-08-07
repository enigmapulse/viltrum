#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);
    sort(all(a)); sort(all(b));
    if(a == b) {
        cout << "YES" << endl;
        return;
    }

    if(n < 2 * m) {
        cout << "NO" << endl;
        return;
    }

    for (ll i = 0; i < m; i++) {
        if(a[i] <= b[i] && b[i] <= a[n - m + i]) continue;
        else {
            cout << "NO" << endl;
            return;
        }
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