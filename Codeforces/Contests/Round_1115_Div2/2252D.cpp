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

    vector<ll> d(n - 1);
    vector<ll> par(n - 1);
    for (ll i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
        par[i] = (d[i] & 1);
    }
    
    vector<vector<ll>> adj;
    vector<ll> curr; curr.push_back(d[0]);
    for (ll i = 1; i < n - 1; i++) {
        if(par[i] == par[i - 1]) {
            curr.push_back(d[i]);
        }
        else {
            adj.push_back(curr);
            curr.clear();
            curr.push_back(d[i]);
        }
    }
    adj.push_back(curr);

    vector<ll> fin;
    for(auto& v : adj) {
        sort(all(v));
        for(auto x : v) fin.push_back(x);
    }
    ll cur = a[0];
    cout << cur << " ";
    for (ll i = 0; i < n - 1; i++) {
        cur += fin[i];
        cout << cur << " ";
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