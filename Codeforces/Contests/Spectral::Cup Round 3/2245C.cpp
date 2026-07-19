#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll f(ll n) {
    ll x = 1;
    while (x - 1 < n)
        x <<= 1;
    return x - 1;
}

void solve() {
    ll n, k; cin >> n >> k;
    if(k > f(n) || ((n & (n - 1)) == 0 && k < n)) {
        cout << "NO" << endl;
        return;
    }

    ll val = k ^ n;
    cout << "YES" << endl;
    if(val == 0) {
        for (ll i = 0; i < n; i++) cout << n - 1 - i << " ";
        cout << endl;
        return;
    }

    vector<ll> vals;
    for(ll i = 0; i < 40; i++) {
        if((val >> i) & 1) vals.push_back((1 << i));
    }

    set<ll> s;
    s.insert(0);
    for(auto x : vals) s.insert(x);
    for (ll i = 0; i < n; i++) {
        if(s.find(i) == s.end()) cout << i << " ";
    }
    for(auto x : s) cout << x << " ";
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