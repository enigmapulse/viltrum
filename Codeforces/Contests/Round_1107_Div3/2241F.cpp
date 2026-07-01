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

    vector<ll> contr(n, 0);
    ll cnt1 = 0;
    for (ll i = 0; i < n; i++) {
        if(s[i] == '1') cnt1++;
        if(s[i] == '0') contr[i] = cnt1;
    }
    ll cnt0 = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if(s[i] == '0') cnt0++;
        if(s[i] == '1') contr[i] = cnt0;
    }
    bool flag = false;
    for (ll i = 0; i < n; i++) flag |= (contr[i] & 1);
    
    ll tot = accumulate(all(contr), 0ll);
    if((tot / 2) & 1) cout << "Alice" << endl;
    else {
        if(flag) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
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