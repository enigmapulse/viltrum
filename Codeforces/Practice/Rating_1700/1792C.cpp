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
    vector<ll> a(n); inarr(a, n);

    auto chk = [&] (ll x) {
        // can we do it in x ops
        ll before = n / 2 - x;
        // allowed range = {n / 2 - k + 1, ..., n / 2, n + 1 - n / 2, ... n - n / 2 + k}
        vector<ll> to_check;
        for (ll i = 0; i < n; i++) {
            if(a[i] >= n / 2 - before + 1 && a[i] <= n - n / 2 + before) to_check.push_back(a[i]);
        }
        bool ret = true;
        for (ll i = 1; i < to_check.size(); i++) {
            ret &= (to_check[i] == to_check[i - 1] + 1);
        }
        return ret;
    };

    ll lo = 0, hi = n / 2;
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
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