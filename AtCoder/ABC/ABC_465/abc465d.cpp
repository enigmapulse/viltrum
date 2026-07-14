#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

vector<ll> nbase(ll n, ll k) {
    vector<ll> res;
    while (n > 0) {
        res.push_back(n % k);
        n /= k;
    }
    reverse(all(res));
    return res;
}

void solve() {
    ll x, y; cin >> x >> y; ll base; cin >> base;
    vector<ll> a = nbase(x, base);
    vector<ll> b = nbase(y, base);

    ll match = 0;
    for (ll i = 0; i < min(a.size(), b.size()); i++) {
        if(a[i] != b[i]) break;
        match++;
    }
    cout << a.size() + b.size() - 2 * match << endl;
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