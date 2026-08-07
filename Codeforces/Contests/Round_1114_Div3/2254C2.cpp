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
    string s, t; cin >> s >> t;

    ll ct_odd = 0, ct_even = 0;
    for (ll i = 0; i < n; i++) {
        if(i & 1 && s[i] == '1') ct_odd++;
        if(i % 2 == 0 && s[i] == '1') ct_even++;
        if(i & 1 && t[i] == '1') ct_odd--;
        if(i % 2 == 0 && t[i] == '1') ct_even--;
    }
    if(!(ct_odd == 0 && ct_even == 0)) {
        cout << -1 << endl;
        return;
    }
    
    vector<ll> idxs_odd, idxt_odd, idxs_even, idxt_even;
    for (ll i = 0; i < n; i++) {
        if(i & 1 && s[i] == '1') idxs_odd.push_back(i);
        if(i % 2 == 0 && s[i] == '1') idxs_even.push_back(i);
        if(i & 1 && t[i] == '1') idxt_odd.push_back(i);
        if(i % 2 == 0 && t[i] == '1') idxt_even.push_back(i);
    }
    
    ll cnt = 0;
    for (ll i = 0; i < idxs_odd.size(); i++) {
        cnt += abs(idxs_odd[i] - idxt_odd[i]) / 2;
    }
    for (ll i = 0; i < idxs_even.size(); i++) {
        cnt += abs(idxs_even[i] - idxt_even[i]) / 2;
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