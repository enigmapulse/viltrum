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
    map<ll, ll> mp, f;
    for (ll i = 0; i < n; i++) {
        f[a[i]]++;
    }
    
    ll idx = 0;
    while(idx < n) {
        ll curr = idx;
        while(curr < n - 1 && a[curr] == a[curr + 1]) curr++;
        mp[a[idx]]++;
        idx = curr + 1;
    }

    ll cnt = 0;
    vector<ll> nums;
    for(auto [val, f] : mp) {
        if(f == 1) continue;
        if(f > 3) {
            cout << "NO" << endl;
            return;
        }
        cnt++; nums.push_back(val);
    }
    if(cnt > 2) {
        cout << "NO" << endl;
        return;
    }
    if(cnt == 0) {
        cout << "YES" << endl;
        return;
    }
    
    if(cnt == 1) {
        for (ll i = 0; i < n; i++) {
            if(f[a[i]] == 1) {
                if()
            }
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