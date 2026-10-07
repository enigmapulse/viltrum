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

    vector<ll> diff;
    for (ll i = 1; i < n; i++) {
        diff.push_back(max(k - a[i] + a[i - 1], 0ll));
    }
    for (ll i = 1; i < diff.size(); i++) {
        diff[i] += diff[i - 1];
    }

    vector<ll> ans(n, 0);
    for (ll i = 1; i < n - 1; i++) {
        ll val = a[i + 1] - a[i - 1];
        if(val <= k) {
            ans[i] = 0;
        }
        ll extra = val - k;
        
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