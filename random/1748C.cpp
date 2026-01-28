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

    vector<ll> pre(n, 0); pre[0] = a[0];
    for (ll i = 1; i < n; i++) pre[i] = a[i] + pre[i - 1];
    
    ll cnt = 0; map<ll, ll> mp; multiset<ll> freq;
    for (ll i = n - 1; i >= 0; i--) {
        if(mp[pre[i]] != 0) freq.erase(freq.find(mp[pre[i]]));
        mp[pre[i]]++; freq.insert(mp[pre[i]]);
        if(a[i] == 0) {
            cnt += *freq.rbegin();
            freq.clear(); mp.clear();
        }
    }
    
    cout << cnt + mp[0] << endl;
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