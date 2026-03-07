#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; vector<ll> a(n); inarr(a, n);
    vector<ll> b(n, 0);
    for (ll i = 1; i < n; i++) {
        b[i] = a[i] - a[i - 1];
    } 
    
    vector<ll> c(n, 0); ll sm = 0;
    for (ll i = 1; i < n - 1; i++) {
        c[i] = b[i + 1] - b[i]; c[i] = c[i] / 2;
        sm += c[i] * i;
    }

    c[n - 1] = (a[0] - sm) / (n - 1);
    sm = accumulate(all(c), 0LL);
    c[0] = (a[0] + a[n - 1])/(n - 1) - sm;
    
    for(ll i = 0; i < n; ++i) cout << c[i] << " ";
    cout << endl;
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