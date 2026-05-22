#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n); inarr(a, n);
    
    ll rem = m, ans = 0;
    for (ll i = 0; i < n; i++) {
        ll slots = rem / (k + 1);
        if(rem % (k + 1) == k) slots++;
        slots = min(slots, a[i] / k);
        ans += slots * k; rem -= slots * (k + 1); a[i] -= slots * k;
        if(rem <= 0) {
            cout << ans << endl;
            return;
        }
    }
    
    if(rem <= 0) {
        cout << ans << endl;
        return;
    }
    sort(all(a), greater());

    for (ll i = 0; i < n; i++) {
        ll mn = min(rem, a[i]);
        ans += mn; rem -= mn;
        if(rem == 0) break;
        else rem--;
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