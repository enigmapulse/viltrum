#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);

    ll cnt0 = a[n - 1], cnt1 = b[m - 1];
    for (ll i = 0; i < n - 1; i++) {
        cnt0 += a[i] - a[i + 1] + 1;
    }
    for (ll i = 0; i < m - 1; i++) {
        cnt1 += b[i] - b[i + 1] + 1;
    }
    
    if(cnt0 >= cnt1) cout << 1 << endl;
    else cout << 2 << endl;
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