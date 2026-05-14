#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, h, k; cin >> n >> k >> h;
    vector<ll> a(n); inarr(a, n);

    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i] >= a[i + 1]) ans += (a[i] - a[i + 1]) * k;
        else {
            ll mn = (a[i + 1] - a[i]) * h;
            ll curr = 0;
            ll u = a[i], v = a[i + 1];
            while(u != v) {
                ll inc = u & -u;
                if(u + inc <= v) u += inc;
                else {
                    mn = min(mn, (u + inc - v) * k + curr);
                    curr += h;
                    u++;
                }
            }
            mn = min(mn, curr);
            ans += mn;
        }
    }
    cout << ans << endl;
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