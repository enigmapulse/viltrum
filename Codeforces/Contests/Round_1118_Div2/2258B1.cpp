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
    vector<ll> a(n); inarr(a, n);

    sort(all(a));
    map<ll, ll> mp;
    for(auto x : a) mp[x]++;

    ll best = 0;
    for (ll i = 1; i <= m; i++) {
        auto it = lower_bound(all(a), i);
        ll curr = 0;
        if(it == a.begin()) curr = a.size();
        else {
            
        }
    }
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