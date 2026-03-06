#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll> ());
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        a[y].push_back(x);
    }

    vector<ll> ans(n + 1, 0), mn(n + 1, 0);

    ll sm = 0;
    multiset<ll> curr; 
    for (ll i = n; i >= 0; i--) {
        for(auto x : a[i]) {
            curr.insert(x);
            sm += x;
        }
        while(curr.size() > i + 1) {
            sm -= *curr.begin();
            curr.erase(curr.begin());
        }
        ans[i] = sm; 
        if(!curr.empty() && curr.size() == i + 1) mn[i] = *curr.begin();
    }

    ll mx = *max_element(all(ans));

    vector<ll> pref(n + 1, 0); pref[0] = ans[0] - mn[0];
    for (ll i = 1; i <= n; i++) {
        pref[i] = max(ans[i] - mn[i], pref[i - 1]);
    }
    
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        cout << max(mx, pref[y] + x) << " ";
    }   
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