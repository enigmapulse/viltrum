#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> r(n); inarr(r, n);

    vector<ll> ans(n, 0);
    function<void(ll)> recur = [&] (ll idx) {
        if(idx == n) {
            ll sm = accumulate(all(ans), 0LL);
            if(sm % k != 0) return;
            for (auto elem : ans) cout << elem << " ";
            cout << endl;
            return;
        }

        for (ll j = 1; j <= r[idx]; j++) {
            ans[idx] = j;
            recur(idx + 1);
        }
    };
    
    recur(0);
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