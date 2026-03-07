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
    vector<ll> mp(1000005, 0); 

    vector<ll> a(n); inarr(a, n);
    for(auto x : a) mp[x]++;

    auto f = [&] (ll num) {
        if(num == 0) return 0LL;
        ll sm = 0;
        ll temp = num;
        while(temp > 0) {
            sm += temp % 10;
            temp /= 10;
        }
        return num - sm;
    };

    for (ll i = 1e6; i > 0; i--) {
        if(mp[i] == 0) continue;
        if(mp[i] >= k) {
            cout << i - f(i) << endl;
            return;
        }
        if(mp[i] < k) {
            ll val = f(i);
            k -= mp[i];
            mp[val] += mp[i];
            mp[i] = 0;
        }
    }
    cout << 0 << endl;
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