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
    string s; cin >> s;

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        mp[s[i] - 'a'].push_back(i);
    }
    
    vector<ll> req(n, 0); req[n - 1] = 1;
    for (ll i = n - 2; i >= 0; i--) {
        ll mn = 1e12;
        for (ll j = 0; j < k; j++) {
            auto it = upper_bound(all(mp[j]), i);
            if(it != mp[j].end()) mn = min(mn, 1 + req[*it]);
            else mn = min(mn, 1ll);
        }
        req[i] = mn;
    }
    
    ll q; cin >> q; 
    while(q--) {
        string x; cin >> x;
        ll curr = -1;
        for(auto ch : x) {
            auto it = upper_bound(all(mp[ch - 'a']), curr);
            if(it == mp[ch - 'a'].end()) {
                curr = -2;
                break;
            } 
            curr = *it;
        }
        if(curr == -2) cout << 0 << endl;
        else cout << req[curr] << endl;
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