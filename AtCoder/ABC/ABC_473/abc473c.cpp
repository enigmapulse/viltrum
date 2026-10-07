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

    map<ll, ll> mp;
    for(auto x : a) mp[x]++;

    ll mx = 0;
    map<ll, ll> mp2;
    for(auto [val, f] : mp) {mp2[f]++; mx = max(mx, f);}
    
    cout << mp2[mx] + (mx ? mp2[mx - 1] : 0ll) << endl;
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