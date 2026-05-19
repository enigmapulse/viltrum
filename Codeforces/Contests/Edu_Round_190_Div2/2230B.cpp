#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s;
    ll n = s.size();
    
    string t; ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if(s[i] == '4') cnt++;
        else t += s[i];
    }
    
    ll m = t.size();
    if(m == 0) {
        cout << cnt << endl;
        return;
    }
    vector<ll> cnt1(m, 0), cnt2(m, 0), cnt3(m, 0);
    if(t[0] == '1') cnt1[0]++;
    if(t[0] == '2') cnt2[0]++;
    if(t[0] == '3') cnt3[0]++;
    for (ll i = 1; i < m; i++) {
        cnt1[i] = cnt1[i - 1];
        cnt2[i] = cnt2[i - 1];
        cnt3[i] = cnt3[i - 1];
        if(t[i] == '1') cnt1[i]++;
        if(t[i] == '2') cnt2[i]++;
        if(t[i] == '3') cnt3[i]++;
    }
    
    ll mn = cnt2[m - 1];
    for (ll i = 0; i < m; i++) {
        mn = min(mn, cnt1[i] + cnt3[i] + cnt2[m - 1] - cnt2[i]);
    }
    cout << mn + cnt << endl;
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