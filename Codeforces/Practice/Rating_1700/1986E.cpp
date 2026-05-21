#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    sort(all(a));
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        mp[a[i] % k].push_back(a[i] / k);
    }
    
    ll om = -1, sm = 0;
    for(auto [mod, arr] : mp) {
        if(arr.size() & 1) {
            if(om == -1) om = mod;
            else {
                cout << -1 << endl;
                return;
            }
        }
        else {
            for (ll i = 0; i < arr.size(); i+=2) {
                sm += arr[i + 1] - arr[i];
            }
        }
    }

    if(om != -1 && mp[om].size() > 1) {
        vector<ll> odd, even;
        for (ll i = 0; i < mp[om].size() - 1; i++) {
            if(i & 1) odd.push_back(mp[om][i + 1] - mp[om][i]);
            else even.push_back(mp[om][i + 1] - mp[om][i]);
        }
        
        ll n = even.size();
        for (ll i = 1; i < n; i++) even[i] += even[i - 1];
        for (ll i = n-2; i >= 0; i--) odd[i] += odd[i + 1];
        
        ll mn = min(even[n - 1], odd[0]);
        for (ll i = 0; i < n - 1; i++) {
            mn = min(even[i] + odd[i + 1], mn);
        }
        sm += mn;
    }

    cout << sm << endl;
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