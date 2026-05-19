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
    string s; cin >> s;

    ll l, r;
    for (ll i = 0; i < n; i++) {
        if(a[i] == 1) l = i + 1;
        if(a[i] == n) r = i + 1;
    }
    if(l > r) swap(l, r);

    if(s[0] == '1' || s[n - 1] == '1' || s[l - 1] == '1' || s[r - 1] == '1') {
        cout << -1 << endl;
    } 
    else {
        cout << 5 << endl;
        cout << l << " " << r << endl;
        cout << 1 << " " << l << endl;
        cout << 1 << " " << r << endl;
        cout << l << " " << n << endl;
        cout << r << " " << n << endl;
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