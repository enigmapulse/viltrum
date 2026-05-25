#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);

    ll tot_and = LLONG_MAX;
    for (ll i = 0; i < n; i++) tot_and &= a[i];

    auto chk = [&] (ll x) {
        // we meed to find the minimum ops to do to
        // ensure that the resulting and is greater than equal to x
        return true;
    };

    while(q--) {
        ll k; cin >> k;
        
        ll lo = 0, hi = 1e6;
        while(lo < hi) {
            ll mid = lo + (hi - lo)/2;
            if(chk(mid)) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << endl;
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