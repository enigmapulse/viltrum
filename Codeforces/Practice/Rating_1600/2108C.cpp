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
    vector<ll> sorted = a; sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());
    for (ll i = 0; i < n; i++) {
        a[i] = lower_bound(all(sorted), a[i]) - sorted.begin();
    }
    
    map<ll, vector<ll>> order;
    for (ll i = 0; i < n; i++) {
        order[-a[i]].push_back(i);
    }
    vector<bool> reached(n, false);

    ll cnt = 0;
    for(auto [val, pos] : order) {
        for(auto idx : pos) {
            if((idx + 1 < n && reached[idx + 1]) || (idx - 1 >= 0 && reached[idx - 1])) {reached[idx] = true;}
        }
        for (auto idx : views::reverse(pos)) {
            if((idx + 1 < n && reached[idx + 1]) || (idx - 1 >= 0 && reached[idx - 1])) {reached[idx] = true;}
        }
        ll need = 0;
        vector<ll> unreached;
        for(auto idx : pos) if(!reached[idx]) unreached.push_back(idx); 
        if(unreached.empty()) continue;
        for (ll i = 1; i < unreached.size(); i++) {
            if(abs(unreached[i] - unreached[i-1]) > 1) need++;
        }
        cnt += need + 1;
        for(auto idx : pos) reached[idx] = true; 
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