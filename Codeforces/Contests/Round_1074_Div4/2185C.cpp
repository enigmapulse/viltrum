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

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll x = -a[i];
        for (ll j = 0; j < n; j++) {
            a[j] += x;
        }

        ll mex = 0;
        map<ll, ll> mp;
        for (ll j = 0; j < n; j++) {
            mp[a[j]]++;
        }
        for (ll j = 0; j < n; j++) {
            if(mp[j]) mex = j + 1;
            else break;
        }
        ans = max(ans, mex);
        
        for (ll j = 0; j < n; j++) {
            a[j] -= x;
        }
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