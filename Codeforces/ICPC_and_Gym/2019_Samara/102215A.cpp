#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp;
    vector<ll> ans(n, 0);
    ll mn = n;
    for (ll i = n - 1; i >= 0; i--) {
        if(a[i] > 0) {
            ans[i] = mn - i;
            mp[a[i]] = i;
        }
        else {
            if(mp.find(abs(a[i])) != mp.end()) mn = min(mn, mp[abs(a[i])]);
            ans[i] = mn - i;
        }
    }
    
    for(auto x : ans) cout << x << " ";
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