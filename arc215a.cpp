#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k, l; cin >> n >> k >> l;
    vector<ll> a(n); inarr(a, n);

    ll left = 0, right = 0; sort(all(a));
    left = a[0]; right = l - a[n - 1];
    vector<ll> diff;
    for (ll i = 1; i < n; i++) diff.push_back(a[i] - a[i - 1]);
    
    sort(all(diff), greater());
    if(k == 1) cout << max({diff[0] / 2, left, right}) << endl;
    else {
        ll ans = max({diff[0] / 2, left, right});
        ll pref = 0;
        for (ll i = 0; i < diff.size(); i++) {
            pref += diff[i] / 2; ll curr = pref;
            if(k < i + 1) break;
            left += diff[i] / 2, right += diff[i] / 2;
            if(k >= i + 2) curr += max(left, right);
            curr += (k - i - 2) * (left + right);
            ans = max(ans, curr);
        }
        cout << ans << endl;
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