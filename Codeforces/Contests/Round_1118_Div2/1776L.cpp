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
    string s; cin >> s;

    ll c = 0, d = 0;
    for(auto x : s) {
        c += (x == '+');
        d += (x == '-');
    }
    if(c < d) swap(c, d);

    ll q; cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        if(c == d) {
            cout << "YES" << endl;
            continue;
        }
        if(a == b) {
            cout << "NO" << endl;
            continue;
        }
        if(a < b) swap(a, b);
        ll g = gcd(a, b);
        a = a / g, b = b / g;
        ll q = c - d, div = a - b;
        ll k = q / div;
        ll x = c - k * a;
        if(x < 0) {
            cout << "NO" << endl;
            continue;;
        }
        if(d == k * b + x) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
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