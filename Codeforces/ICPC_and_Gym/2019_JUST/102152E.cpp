#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    string s, c, p; cin >> s >> c >> p;

    map<char, vector<ll>> mp;
    for (ll i = 0; i < n; i++) {
        mp[s[i]].push_back(c[i] - '0');
    }
    
    map<char, ll> freq;
    for(auto ch : p) freq[ch]++;

    ll ans = 0;
    for(auto [ch, f] : freq) {
        ll cnt = 0;
        if(f > mp[ch].size()) {
            cout << -1 << endl;
            return;
        }
        sort(all(mp[ch]));
        for(auto cost : mp[ch]) {
            if(cnt == f) break;
            else {
                cnt++; ans += cost;
            }
        }
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