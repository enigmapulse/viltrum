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
    string s, t; cin >> s >> t;
    ll cnt0 = 0, cnt1 = 0;
    for(auto ch : s) if(ch == '1') cnt1++; else cnt0++;

    for(ll i = 0; i < t.size(); i++) {
        auto ch = t[i];
        if (cnt0 == 0 || cnt1 == 0){
            cout << "NO" << endl;
            return;
        }
        if(ch == '1') cnt0--;
        if(ch == '0') cnt1--;
        if(cnt0 < 0 || cnt1 < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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