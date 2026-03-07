#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

ll nxtpow(ll n) {
    if (n <= 0) return 1;
    if ((n & (n - 1)) == 0) n++;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return n + 1;
}

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;
    if(x == n) {
        cout << n << endl;
        return;
    }
    if(x > n || ((n & x) != x)) {
        cout << -1 << endl;
        return;
    }
    ll diff = n - x; ll p = nxtpow(diff);
    if(p == diff) p <<= 1;
    if(x & (p - 1)) {
        cout << -1 << endl;
        return;
    }
    if((n & (n + p - diff)) == x) cout << n + p - diff << endl;
    else cout << -1 << endl;
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