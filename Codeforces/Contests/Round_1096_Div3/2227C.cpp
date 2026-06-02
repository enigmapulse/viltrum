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

    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        if(a[i] % 6 == 0) ans.push_back(a[i]);
    }
    for (ll i = 0; i < n; i++) {
        if(a[i] % 2 == 0 && a[i] % 3 != 0) ans.push_back(a[i]);
    }
    for (ll i = 0; i < n; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 != 0) ans.push_back(a[i]);
    }
    for (ll i = 0; i < n; i++) {
        if(a[i] % 2 != 0 && a[i] % 3 == 0) ans.push_back(a[i]);
    }
    
    for(auto x : ans) cout << x << " ";
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