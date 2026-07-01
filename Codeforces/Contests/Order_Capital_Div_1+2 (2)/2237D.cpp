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
    string s; cin >> s;

    vector<ll> pref(n, 0);
    for (ll i = 0; i < n; i++) {
        pref[i] = (s[i] - '0') + 1;
        if(i) pref[i] = (pref[i] + pref[i - 1]) % 3;
    }
    
    ll ans = 0; vector<ll> cnt = {1, 0, 0};
    for (ll i = 0; i < n; i++) {
        ans += i + 1 - cnt[pref[i]];
        cnt[pref[i]]++;
    }
    
    ll idx = 0;
    while(idx < n) {
        ll sz = 1;
        while(idx < n - 1 && s[idx] != s[idx + 1]) {
            sz++; idx++;
        }
        if(sz >= 3) {
            ll pos1 = sz / 2, pos2 = sz - pos1;
            ans -= (pos1 * (pos1 - 1)) / 2;
            ans -= (pos2 * (pos2 - 1)) / 2;
        }
        idx++;
    }
    cout << ans << endl;
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