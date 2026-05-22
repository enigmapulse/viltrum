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

    ll mn = 1e15;
    for (ll i = 0; i < n; i++) {
        ll val = a[i];

        ll f = -1;
        for (ll j = 0; j < n; j++) {
            if(a[j] == val) {f = j; break;}
        }
        
        ll s = -1;
        for (ll j = n - 1; j >= 0; j--) {
            if(a[j] == val) {s = j; break;}
        }

        if(f != s) mn = min(mn, f + n - 1 - s);
    }
    if(mn == 1e15) cout << -1 << endl;
    else cout << mn << endl;
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