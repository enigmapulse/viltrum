#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, h; cin >> n >> m >> h;
    vector<ll> a(n); inarr(a, n);
    vector<ll> f(n), cleared(n, 0);
    for (ll i = 0; i < n; i++) f[i] = a[i];
    
    ll cl = 0;
    for (ll i = 0; i < m; i++) {
        ll b, c; cin >> b >> c;
        if(cleared[b - 1] != cl) {
            f[b - 1] = a[b - 1];
            cleared[b - 1] = cl;
        }
        f[b - 1] += c;
        if(f[b - 1] > h) {
            cl++;
            f[b - 1] = a[b - 1]; cleared[b - 1]++;
        }
    }

    for (ll i = 0; i < n; i++) {
        if(cleared[i] != cl) {
            f[i] = a[i];
        }
    }
    
    for(auto y : f) cout << y << " ";
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