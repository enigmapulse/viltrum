#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

using i128 = __int128_t;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    auto chk = [&] (i128 x) {
        i128 ops = 0;
        for (ll i = 0; i < n; i++) {
            if((i128)a[i] >= x) continue;
            ops += (x - a[i] + i) / (i + 1);
            if (ops > k) return false;
        }
        return (ops <= k);
    };

    ll lo = 1, hi = 2e18;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
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