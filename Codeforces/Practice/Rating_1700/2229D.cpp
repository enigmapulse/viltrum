#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);
    if(n == 1) {
        cout << min(a[0], b[0]) << endl;
        return;
    }

    auto chk = [&] (ll x) {
        vector<ll> f;
        for (ll i = 0; i < n; i++) {
            ll t1 = (a[i] >= x), t2 = (b[i] >= x);
            if(t1 + t2 == 1 || (!f.empty() && t1 + t2 == 0 && f.back() == 0)) continue;
            f.push_back(t1 + t2);
        }
        if(f.empty()) return false;
        ll cnt = 0;
        for (ll i = 0; i < f.size(); i++) {
            cnt += (f[i] == 2);
        }
        return (cnt > f.size() - cnt);
    };

    ll lo = 1, hi = 2*n;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
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