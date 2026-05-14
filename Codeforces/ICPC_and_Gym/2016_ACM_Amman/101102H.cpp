#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >>n >> k;
    string s; cin >> s;

    bool chk = false;
    ll idx = 0;
    while(idx < n) {
        ll cnt = 0;
        while(idx < n && s[idx] == '0') {idx++; cnt++;}
        if(cnt >= k + 1) chk = true;
        idx++;
    }

    if(chk) cout << "yes" << endl;
    else cout << "no" << endl;
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