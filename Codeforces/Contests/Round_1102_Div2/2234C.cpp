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
    vector<ll> h(n); invec(h);

    for (ll v = 0; v < n; ++v) {
        vector<ll> L(n, 0), R(n, 0);
        ll mxh = 0, curr = v;
        for (ll k = 1; k < n; ++k) {
            mxh = max(mxh, h[curr]);
            ll nxt = (curr + 1) % n;
            L[nxt] = mxh;
            curr = nxt;
        }
        mxh = 0; curr = v;
        for (ll k = 1; k < n; ++k) {
            ll prev = (curr - 1 + n) % n;
            mxh = max(mxh, h[prev]);
            R[prev] = mxh;
            curr = prev;
        }
        ll vol = 0;
        for (ll i = 0; i < n; ++i) {
            if (i != v) vol += min(L[i], R[i]);
        }
        
        cout << vol << " ";
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