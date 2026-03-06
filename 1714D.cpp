#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s;
    ll n; cin >> n;
    vector<string> t; 
    for(ll i = 0; i < n; ++i) {
        string x; cin >> x;
        t.push_back(x);
    }

    vector<pair<ll, ll>> ops;
    pair<ll, ll> curr;
    ll idx = n; 
    while(idx != n) {
        for(ll i = 0; i < t.size(); ++i) {
            
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