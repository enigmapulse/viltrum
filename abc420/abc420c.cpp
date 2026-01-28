#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);
    ll mn = 0;
    for (ll i = 0; i < n; i++) mn += min(a[i], b[i]);

    while(q--) {
        char op; ll idx, val;
        cin >> op >> idx >> val;
        ll curr = min(a[idx - 1], b[idx - 1]);
        if(op == 'A') a[idx - 1] = val;
        else b[idx - 1] = val;
        ll nw = min(a[idx - 1], b[idx - 1]);
        mn += nw - curr;
        cout << mn << endl;
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