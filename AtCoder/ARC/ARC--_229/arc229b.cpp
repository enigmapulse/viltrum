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

    auto st = a;
    sort(all(st), greater());
    if(st != a) {
        cout << -1 << endl;
        return;
    }

    ll cnt = 0;
    while(a[0] != 0) {
        ll l = a[n - 1], r = a[n - 1];
        for (ll i = n - 2; i >= 0; i--) {
            ll nl = 2 * l;
            ll nr = 2 * r + 1;
            nr = min(a[i], nr);
        }
        for (ll i = 0; i < n; i++) {
            a[i] -= nr;
            
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