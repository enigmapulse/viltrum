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

    ll ans = 0; sort(all(a));
    map<ll, ll> mp; for(auto x : a) mp[x]++;
    for (ll i = 0; i < n - 2*k; i++) {ans += a[i]; mp[a[i]]--;}

    ll mx = 0; ll sm = 0;
    map<ll, bool> done;
    for (ll i = n - 2*k; i < n; i++) {
        mx = max(mx, mp[a[i]]);
        if (!done[a[i]]) {
            sm += mp[a[i]];
            done[a[i]] = true;
        }
    }

    ll extra = 0;
    if(2 * mx > sm) extra += (mx - sm/2);

    cout << ans + extra << endl;
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