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

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) mp[a[i]].push_back(i);
    
    ll curr = 0; vector<ll> ans(n);
    for(auto [val, idxs] : mp) {
        if(idxs.size() % val) {
            cout << -1 << endl;
            return;
        }

        for (ll i = 0; i < idxs.size(); i++) {
            curr += (i % val == 0);
            ans[idxs[i]] = curr;
        }
    }

    for(auto vl : ans) cout << vl << " ";
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