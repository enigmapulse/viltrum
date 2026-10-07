#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);

    auto cost = [&] (ll x) {
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            cnt += max(x - a[i], 0ll);
        }
        for (ll i = 0; i < m; i++) {
            cnt += max(b[i] - x, 0ll);
        }
        return cnt;
    };

    ll lo = 0, hi = 1e15;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        ll slope = cost(mid + 1) - cost(mid);
        if(slope >= 0) hi = mid;
        else lo = mid + 1;
    }
    cout << cost(lo) << endl;
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