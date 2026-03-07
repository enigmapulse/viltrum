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
    vector<vector<ll>> a(n);
    for (ll i = 0; i < n; i++) {
        ll t; cin >> t;
        vector<ll> s;
        for(ll j = 0; j < t; ++j) {
            ll x; cin >> x;
            s.push_back(x);
        }
        reverse(all(s)); map<ll, bool> used;
        vector<ll> b;
        for(auto x : s) {
            if(!used[x]) {b.push_back(x); used[x] = true;}
        }
        a[i] = b;
    }

    map<ll, bool> used;
    auto ops = [&] (vector<ll>& a, vector<ll>& b) {
        vector<ll> c, d;
        for(auto x : a) {
            if(!used[x]) c.push_back(x);
        }
        for(auto x : b) {
            if(!used[x]) d.push_back(x);
        }
        return (c < d);
    };
 
    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        ll idx = i;
        for (ll j = i; j < n; j++) {
            if(ops(a[j], a[idx])) idx = j;
        }
        for(auto x : a[idx]) {
            if(used[x]) continue;
            used[x] = true;
            ans.push_back(x);
        }
        swap(a[i], a[idx]);
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