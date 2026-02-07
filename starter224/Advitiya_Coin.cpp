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
    vector<ll> a(n); inarr(a, n);
    a.push_back(0);

    ll mn = a[0], mx = a[0];
    ll res = 0;
    for (ll i = 1; i < n; i++) {
        if(abs(a[i] - mn) > k || abs(mx - a[i]) > k) {
            res++;
            mn = a[i + 1];
            mx = a[i + 1];
        }
        else {
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
    }
    
    cout << res << endl;
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