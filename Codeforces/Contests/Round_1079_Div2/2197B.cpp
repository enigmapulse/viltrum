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
    vector<ll> p(n), a(n); inarr(p, n); inarr(a, n);

    bool chk = true;
    a.erase(unique(all(a)), a.end());
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        mp[p[i]] = i;
    }
    for (ll i = 0; i < a.size() - 1; i++) {
        chk &= (mp[a[i]] < mp[a[i + 1]]);
    }
    
    if(chk) cout << "YES" << endl;
    else cout << "NO" << endl;
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