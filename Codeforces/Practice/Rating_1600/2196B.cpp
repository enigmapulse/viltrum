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

    vector<vector<ll>> mp(n);
    for (ll i = 0; i < n; i++) {
        if(a[i] < n) mp[a[i]].push_back(i);
    }
    
    ll cnt = 0;
    for (ll k = 1; k < n; k++) {
        for (ll i = 1; i * i <= k; i++) {
            if(k % i != 0) continue;
            ll x = i, y = k / i;
            // I need to count pairs which have a[j] = i and a[j + k] = k / i
            if(mp[x].size() > mp[y].size()) swap(x, y);
            for(auto idx : mp[x]) {
                if(idx - k >= 0 && a[idx - k] == y) cnt++;
                if(x != y && idx + k < n && a[idx + k] == y) cnt++;
            }
        }
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