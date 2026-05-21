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

    auto chk = [&] (ll k) {
        string t = s; ll curr = 0;
        vector<ll> end(n + 1, 0);
        for (ll i = 0; i < n - k + 1; i++) {
            curr += end[i];
            if(t[i] - '0' == (curr & 1)) {
                t[i] = '1';
                curr++;  end[i + k] = -1;
            } 
        }
        bool chk = true;
        for (ll i = n - k + 1; i < n; i++) {
            curr += end[i];
            chk &= (t[i] - '0' != (curr & 1));
        }
        return chk;
    };

    for (ll len = n; len > 0; len--) {
        if(chk(len)) {
            cout << len << endl;
            return;
        }
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