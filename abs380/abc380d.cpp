#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s; cin >> s;
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    for (ll i = 0; i < n; i++) {
        ll k = a[i] - 1;
        ll q = k / (s.size()); ll rem = k % (s.size());
        ll cnt = __builtin_popcountll(q);
        cnt = cnt % 2;
        if(cnt) cout << char(s[rem] ^ 32) << " ";
        else cout << s[rem] << " ";
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