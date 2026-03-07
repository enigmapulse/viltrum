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

    vector<ll> suff(n, 0); 
    for (ll i = 0; i < n; i++) {
        ll val = a[i]/2; ll idx = i;
        while(val > 0 && idx >= 0) {
            suff[idx] += val;
            val /= 2; idx--;
        }
    }

    vector<ll> pref(n, 0); pref[0] = a[0];
    for (ll i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];
    
    ll mx = max(pref[n - 1] - n * k, suff[0]);
    for (ll i = 1; i < n; i++) {
        mx = max(mx, pref[i - 1] + suff[i] - i * k);
    }
    
    cout << mx << endl;
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