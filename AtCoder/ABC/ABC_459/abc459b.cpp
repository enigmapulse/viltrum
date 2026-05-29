#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n; string s;
    for (ll i = 0; i < n; i++) {
        string x; cin >> x;
        s += x[0];
    }

    vector<ll> mp(30);
    mp[0] = mp[1] = mp[2] = 2;
    mp[3] = mp[4] = mp[5] = 3;
    mp[6] = mp[7] = mp[8] = 4;
    mp[9] = mp[10] = mp[11] = 5;
    mp[12] = mp[13] = mp[14] = 6;
    mp[15] = mp[16] = mp[17] = mp[18] = 7;
    mp[19] = mp[20] = mp[21] = 8;
    mp[22] = mp[23] = mp[24] = mp[25] = 9;
    
    for(auto ch : s) {
        cout << mp[ch - 'a'];
    }
    cout << endl;
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