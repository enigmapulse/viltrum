#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, p, q, r; 
    cin >> a >> b >> p >> q >> r;
    
    ll cost = 1e15;
    for (ll i = 0; i <= min(a, b); i++) {
        ll ra = a - i;
        ll rb = b - i;
        ll curr = (i * r) + (((ra + 1) / 2) * p) + (((rb + 1) / 2) * q);
        cost = min(cost, curr);
    }
    
    cout << cost << endl;
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