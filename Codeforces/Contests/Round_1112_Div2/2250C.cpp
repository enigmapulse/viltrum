#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> l(n + 1), r(n + 1), u(n + 1), v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> l[i] >> r[i] >> u [i] >> v[i];
    }

    auto chk = [&] (ll len) {
        ll idx = 1;
        ll left = 1, right = len;
        while (idx <= n) {
            if((l[idx] > left || r[idx] < left) && (u[idx] > right || v[idx] < right)) {
                left++; right--;
            }
            idx++;
            if(right == 0) {
                return true;
            }
        }
        return false;
    };
    
    ll ans = 0;
    for (ll len = 1; len <= n; len++) {
        if(chk(len)) ans = len;
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