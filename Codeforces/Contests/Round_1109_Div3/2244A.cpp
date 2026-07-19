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
    ll mx = 0;
    ll idx = 0;
    while (idx < n) {
        ll cnt = 0;
        if(s[idx] == '*') {idx++; continue;}
        while(idx < n && s[idx] == '#') {cnt++; idx++;}
        mx = max(mx, cnt);
    }
    cout << (mx + 1)/2 << endl;
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