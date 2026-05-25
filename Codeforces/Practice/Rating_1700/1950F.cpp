#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c ; cin >> a >> b >> c;

    if(c != a + 1) {
        cout << -1 << endl;
        return;
    }

    if(a == 0) {
        cout << b << endl;
        return;
    }
    
    ll H = 0;
    while (((1LL << H) - 1) < a) {
        H++;
    }

    ll inside = a - ((1LL << (H - 1)) - 1);
    ll leafH = 2 * inside;
    ll bleafH = c - leafH;
    ll lim = bleafH;

    if (b <= lim) {
        cout << H << endl;
    } else {
        ll rem = b - lim;
        ll ext = (rem + c - 1) / c; 
        cout << H + ext << endl;
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