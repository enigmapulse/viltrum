#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);
    vector<ll> sm = a;
    for (ll i = 0; i < n; i++) sm.push_back(a[i]);
    for (ll i = 1; i < sm.size(); i++) sm[i] += sm[i - 1];
    
    while (q--) {
        ll l, r; cin >> l >> r; l--; r--;
        ll sft1 = l / n, sft2 = r / n;
        l = l % n, r = r % n;
        ll cnt = sft2 - sft1 - 1;
        ll ans = 0;
        ans += cnt * sm[n - 1];
        ans += sm[n - 1 + sft1] - (l + sft1 > 0 ? sm[l - 1 + sft1] : 0); 
        ans += sm[r + sft2] - (sft2 > 0 ? sm[sft2 - 1] : 0); 
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