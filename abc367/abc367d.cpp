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
    vector<ll> a(n); inarr(a, n);
    for (ll i = 0; i < n; i++) a.push_back(a[i]);

    vector<ll> pre; ll curr = 0;
    pre.push_back(0);
    for(auto elem : a) {
        curr += elem;
        pre.push_back(curr % m);
    }

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        mp[pre[i]]++;
    }
    
    ll cnt = 0;
    ll l = 0, r = n - 1;
    for (ll l = 0; l < n; l++) {
        cnt += mp[pre[l]] - 1;
        mp[pre[l]]--; r++;
        mp[pre[r]]++;
    }
    
    cout << cnt << endl;
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