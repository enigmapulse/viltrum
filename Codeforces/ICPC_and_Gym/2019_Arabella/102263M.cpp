#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s; cin >> s;

    map<char, ll> mp;
    for(auto ch : s) mp[ch]++;

    for(auto ch = 'a'; ch <= 'z'; ch++) {
        if(ch != 'z') {
            mp[char(ch + 1)] += mp[ch] / 2;
            mp[ch] -= (mp[ch] / 2) * 2;
        }
    }

    for (auto ch = 'z'; ch >= 'a'; ch--) {
        for (ll i = 0; i < mp[ch]; i++) cout << ch;
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