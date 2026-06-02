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

    vector<ll> suffmn(n), change(n); suffmn[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        suffmn[i] = min(suffmn[i + 1], a[i]);
    }

    ll idx = -1;
    for (ll i = 0; i < n; i++) {
        change[i] = idx;
        if(i != n - 1 && suffmn[i] != suffmn[i + 1]) idx = i;
    }
    
    ll cost = 0;
    for (ll i = 0; i < n - 1; i++) {
        cost += max(a[i] - suffmn[i + 1], 0ll);
    }
    ll ans = cost;
    for (ll i = 0; i < n; i++) {
        ll start = change[i] + 1; // first idx of the curr seg
        ll sz = i - start;
        ll ncost = cost + sz;
        ans = max(ans, ncost);
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