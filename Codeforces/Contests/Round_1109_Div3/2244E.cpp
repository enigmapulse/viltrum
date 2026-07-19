#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    string s; cin >> s;

    string t(n, ' ');
    for (ll i = 0; i < n; i++) {
        if(i & 1) {
            if (s[i] == '1') t[i] = '0';
            else t[i] = '1';
        }
        else {
            if (s[i] == '0') t[i] = '0';
            else t[i] = '1';
        }
    }
    
    vector<ll> pre(n, 0);
    for (ll i = 1; i < n; i++) {
        if(t[i] != t[i - 1]) pre[i] = 1;
        pre[i] += pre[i - 1];
    }

    while (q--) {
        ll l, r, k; cin >> l >> r >> k;
        ll changes = pre[r - 1] - pre[l - 1];
        ll f = (changes + 1) / 2, s = changes + 1 - f;
        ll mn = min(f, s);
        if(mn <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
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