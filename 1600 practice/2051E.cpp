#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    inarr(a, n); inarr(b, n);
    sort(all(a)); sort(all(b));

    vector<ll> possible;
    for (ll i = 0; i < n; i++) {
        possible.push_back(a[i]);
        possible.push_back(b[i]);
    }
    
    sort(all(possible));

    ll ans = 0;
    for(auto p : possible) {
        auto it = lower_bound(all(a), p) - a.begin();
        auto ut = lower_bound(all(b), p) - b.begin();
        ll buy = n - ut;

        if(it - ut <= k) ans = max(ans, buy*p); 
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