#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;

    ll a = -1, b = -1; ll n = s.size();
    for (ll i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            a = i;
            break;
        }
    }
    if(a == -1) {cout << "YES" << endl; return;}

    for (ll i = n - 1; i >= 0; i--) {
        if(s[i] != t[i]) {
            b = i;
            break;
        }
    }
    if(b == -1) {cout << "YES" << endl; return;}
    
    for (ll i = b; i >= a; i--) {
        if(s[i] != t[b + a - i]) {
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