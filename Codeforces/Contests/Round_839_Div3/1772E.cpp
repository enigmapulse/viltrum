#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; vector<ll> a(n); inarr(a, n);

    set<ll> s, t;
    for (ll i = 0; i < n; i++) {
        if(a[i] != i + 1) s.insert(a[i]);
    }
    for (ll i = n; i >= 1; i--) {
        if(a[n - i] != i) t.insert(a[n - i]);
    }
    
    set<ll> common;
    for(auto x : s) {
        if(t.find(x) != t.end()) {
            common.insert(x);
            t.erase(x);
        }
    }
    for(auto y : common) s.erase(y);

    ll diff = abs((ll)s.size() - (ll)t.size());
    if(s.size() < t.size() && diff >= common.size()) cout << "First" << endl;
    else if(s.size() > t.size() && diff > common.size()) cout << "Second" << endl;
    else {
        if(!common.empty()) cout << "Tie" << endl;
        else cout << "First" << endl;
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