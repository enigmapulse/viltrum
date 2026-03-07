#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<string> a(n); inarr(a, n);

    bool chk = true;
    for (ll sm = 0; sm < 2*n - 1; sm++) {
        char val = 'a';
        for (ll i = 0; i < n; i++) {
            ll j = sm - i;
            if(j >= 0 && j < n) {
                if (a[i][j] != '?') {
                    if(val == 'a') val = a[i][j];
                    else if(val != a[i][j]) chk = false; 
                }
            }
        }
        if(val == 'a') val = '0';
        for (ll i = 0; i < n; i++) {
            ll j = sm - i;
            if(j >= 0 && j < n) {
                if (a[i][j] == '?') a[i][j] = val;
            }
        }
    }
    
    if(!chk) cout << -1 << endl;
    else {
        for (ll i = 0; i < n; i++) {
            cout << a[i] << endl;
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