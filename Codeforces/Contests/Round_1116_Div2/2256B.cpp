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

    bool chk1 = false, chk0 = false;
    for (ll i = 0; i < n; i++) {
        if(i & 1) {if(s[i] != '?') chk1 = true;}
        else {if(s[i] != '?') chk0 = true;}
    }
    if(!chk1 && !chk0) {
        cout << 4 << endl;
        return;
    }

    bool a = true, b = true, c = true, d = true;
    for (ll i = 0; i < n; i++) {
        if (s[i] != '?') {
            int val = s[i] - '0';
            if (i % 2 == 0) {
                if (val != (i / 2) % 2) a = false;
                if (val != 1 - (i / 2) % 2) b = false;
            } 
            else {
                if (val != (i / 2) % 2) c = false;
                if (val != 1 - (i / 2) % 2) d = false;
            }
        }
    }
    cout << (a + b) * (c + d) << endl;
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