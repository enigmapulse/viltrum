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

    ll tot0 = 0, tot1 = 0;
    for(auto x : s) {
        if(x == '1') tot1++;
        else tot0++;
    }

    ll cnt0 = 0, cnt1 = 0;
    for (ll i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            if(s[i] == '0') cnt0++;
            else cnt1++;
        }
    }
    
    string t = s;
    t.erase(unique(all(t)), t.end());
    ll extra0 = 0, extra1 = 0;
    ll sz = t.size();
    if(t[0] == '0') extra0++;
    else extra1++;
    if(t[sz - 1] == '0') extra0++;
    else extra1++;
    if(sz == 1) {
        if(t[0] == '0') extra0--;
        else extra1--;
    }

    
    bool chk = false;
    if(abs(cnt0 - cnt1) < 2) chk = true;
    if(cnt0 > cnt1) {
        if(cnt1 + extra1 >= cnt0 - 1) {chk = true; cnt1 = cnt0 - 1;}
    }
    else if(cnt1 > cnt0) {
        if(cnt0 + extra0 >= cnt1 - 1) {chk = true; cnt0 = cnt1 - 1;}
    }
    if(chk) {
        cout << cnt0 + cnt1 << endl;
    }
    else cout << -1 << endl;
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