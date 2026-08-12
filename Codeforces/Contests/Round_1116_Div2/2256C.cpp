#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    ll f1 = 0, f0 = 0;
    ll v1 = 0, v0 = 0;
    for (ll i = 0; i < 2*n; i++) {
        ll nxt = (i + 1) % (2*n);
        if(i & 1) {
            if(s[i] == '1' && s[nxt] == '1') f1++;
            if(s[i] == '1' && s[nxt] == '0') v1++;
        }
        else {
            if(s[i] == '1' && s[nxt] == '1') f0++;
            if(s[i] == '1' && s[nxt] == '0') v0++;
        }
    }
    cout << f1 + v0 << " " << f0 + v1 << endl;
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