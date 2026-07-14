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
    string a(n, '0'), b(n, '0'), c(n, '0');
    
    for (ll i = n - 1; i >= 0; i--) {
        if(k) {
            c[i] = '1';
            k--;
        }
    }
    
    for (ll i = n - 1; i >= 0; i--) {
        if(k) {
            b[i] = '1';
            k--;
        }
        if(k) {
            a[i] = '1';
            k--;
        }
    }

    cout << a << b << c << endl;
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