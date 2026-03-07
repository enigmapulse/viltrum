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

    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) mp[a[i]] = i;
    if((mp[1] != 0 && mp[1] != n - 1) && (mp[2] != 0 && mp[2] != n - 1)) {
        cout << "NO" << endl;
        return;
    }

    set<ll> s;
    s.insert(abs(mp[1] - mp[2]));
    for (ll i = 3; i <= n; i++) {
        ll idx = mp[i];
        auto it = s.lower_bound(idx);
        auto ut = it; --ut;
        ll diff1 = abs(*it - idx), diff2 = abs(idx - *ut);
    }

    cout << "YES" << endl;
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