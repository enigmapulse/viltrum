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
    if(n == 1) {
        cout << (a[0] > 2 ? a[0] : 0) << endl;
        return;
    }
    sort(all(a), greater());
    ll cnt = 0, saved = 0, idx = -1, ct = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] > 1) {cnt += a[i]; ct++; saved += max((a[i] - 2) / 2, 0LL);}
        else {idx = i; break;}
    }
    
    if(idx == -1) cout << cnt << endl;
    else {
        ll tot = n - idx;
        if(ct == 1) cnt += min(tot, cnt / 2);
        else cnt += min(tot, saved);
        cout << cnt << endl;
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