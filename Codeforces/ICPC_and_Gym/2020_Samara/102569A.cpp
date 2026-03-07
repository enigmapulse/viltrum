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
    vector<ll> a(n); inarr(a, n);

    ll sm = 0, curr = 1;
    for (ll i = n - 1; i>= 0; i--) {
        sm += curr * a[i];
        curr = curr * (-1);
    }
    
    ll q; cin >> q;
    while(q--) {
        ll l, r, v; cin >> l >> r >> v;
        if((r - l + 1) & 1) {
            if((n & 1) == (l & 1)) sm += v;
            else sm -= v;
        }

        cout << sm << endl;
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