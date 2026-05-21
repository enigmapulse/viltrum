#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q; 
    vector<ll> a(n); inarr(a, n);
    string s; cin >> s;
    
    for (ll i = 1; i < n; i++) a[i] += a[i - 1];
    auto sm = [&] (ll l) {return ((l + 1) * (l + 2)) / 2;};

    set<ll> idx;
    for (ll i = 0; i < n - 1; i++) {
        if(s[i] == 'L' && s[i + 1] == 'R' && sm(i) != a[i]) idx.insert(i);
    }
    
    while(q--) {
        ll x; cin >> x; x--;
        if(s[x] == 'L') {
            s[x] = 'R';
            if(s[x - 1] == 'L' && sm(x - 1) != a[x - 1]) idx.insert(x - 1);
            if(s[x + 1] == 'R') {
                auto it = idx.find(x);
                if(it != idx.end()) idx.erase(it);
            } 
        }
        else {
            s[x] = 'L';
            if(s[x + 1] == 'R' && sm(x) != a[x]) idx.insert(x);
            if(s[x - 1] == 'L') {
                auto it = idx.find(x - 1);
                if(it != idx.end()) idx.erase(it);
            } 
        }
        if(idx.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
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