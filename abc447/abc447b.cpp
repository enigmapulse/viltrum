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
    vector<ll> f(26, 0);
    for(auto ch : s) f[ch - 'a']++;
    set<char> ch;
    ll mx = *max_element(all(f));
    for(ll i = 0; i < 26; ++i) if(f[i] == mx) ch.insert(char('a' + i));
    string t;
    for(auto c : s) {
        if(ch.find(c) == ch.end()) t += c;
    }
    cout << t << endl;
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