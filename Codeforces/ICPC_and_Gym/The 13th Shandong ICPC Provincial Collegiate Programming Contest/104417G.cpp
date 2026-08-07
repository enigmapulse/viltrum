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

    map<ll, vector<ll>> cnt;
    for (ll i = 0; i < n; i++) {
        cnt[a[i] - i].push_back(a[i]);
    }
    
    ll ans = 0;
    for(auto& [_, grp] : cnt) {
        sort(all(grp), greater());
        ll val = 0, sm = 0;
        for(ll idx = 0; idx < grp.size(); idx++) {
            sm += grp[idx];
            if(idx & 1) val = max(val, sm);
        }
        ans += max(0ll, val);
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