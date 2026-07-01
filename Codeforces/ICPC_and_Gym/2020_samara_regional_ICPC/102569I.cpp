#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<pll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    
    vector<queue<ll>> mp(200005);
    for(auto [v, c] : a) {
        mp[c].push(v);
    }
    stable_sort(all(a), [](const auto &a, const auto &b) {return a.first < b.first;});

    for(auto [v, c] : a) {
        if(mp[c].front() != v) {
            cout << "NO" << endl;
            return;
        }
        mp[c].pop();
    }
    cout << "YES" << endl;
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