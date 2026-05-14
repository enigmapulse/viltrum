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

    ll cnt = 0; bool zero = false;
    for (ll i = 0; i < n; i++) {
        if(a[i] < 0) cnt++;
        if(a[i] == 0) zero = true;
    }
    
    if(k <= cnt) {
        sort(all(a));
        for (ll i = 0; i < k; i++) {
            a[i] = -a[i];
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += a[i];
        }
        cout << ans << endl;
        return;
    }

    if(k > cnt) {
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += abs(a[i]);
            a[i] = abs(a[i]);
        }
        sort(all(a));
        if(zero) {
            cout << ans << endl;
        }
        else if((k - cnt) & 1) {
            cout << ans - 2 * a[0] << endl;
        }
        else cout << ans << endl;
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