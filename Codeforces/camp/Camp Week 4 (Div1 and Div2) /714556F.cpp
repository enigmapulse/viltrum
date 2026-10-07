#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> a(n); inarr(a, n);

    sort(all(a));

    ll idx = 0;
    while (idx < n) {
        ll l = idx, r = idx;
        while(r + 1 < n && a[r + 1] - a[r] <= d) {
            r++;
        }
        ll med = a[(l + r) / 2];
        ll nl = 
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