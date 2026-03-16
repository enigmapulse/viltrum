#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, l, r; cin >> n >> l >> r;
    string s; cin >> s;

    ll ans = 0;
    map<char, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        char ch = s[i];
        mp[ch].push_back(i);

        ll lo = i - r, hi = i - l;
        auto it = lower_bound(all(mp[ch]), lo);
        auto ut = upper_bound(all(mp[ch]), hi);
        ans += ut - it;
    }
    
    cout << ans << endl;
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