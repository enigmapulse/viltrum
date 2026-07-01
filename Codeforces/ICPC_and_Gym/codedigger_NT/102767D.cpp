#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) mp[a[i]]++;
    
    if(mp[*max_element(all(a))] > 1) {
        cout << 0 << endl;
        return;
    }
    mp[*max_element(all(a))] = 0;

    ll ans = 1;
    for(auto [v, cnt] : mp) {
        if(cnt == 1) ans = (2 * ans) % MOD;
        else if(cnt > 2) {ans = 0; break;}
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