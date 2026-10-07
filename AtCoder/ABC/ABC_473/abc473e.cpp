#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);
    vector<ll> pre(n); pre = a;
    for (ll i = 1; i < n; i++) {
        pre[i] += pre[i - 1];
    }
    map<ll, ll> mp; ll mx = 0;
    mp[0] = 0;
    for (ll i = 0; i < n; i++) {
        ll mod = pre[i] % k;
        ll val = 0;
        if(mp.find(mod) == mp.end()) {
            val = mx;
        }
        else {
            val = max(mx, mp[mod] + 1);
        }
        mp[mod] = val;
        mx = val;
    }
    cout << mx << endl;
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