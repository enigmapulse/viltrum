#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    
    if(s.size() == n) cout << "Yes" << endl; else cout << "No" << endl;
    if(s.size() == m) cout << "Yes" << endl; else cout << "No" << endl;
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