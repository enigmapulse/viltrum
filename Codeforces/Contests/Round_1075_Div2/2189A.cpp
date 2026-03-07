#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, h, l; cin >> n >> h >> l;
    ll cnt1 = 0, cnt2 = 0;
    ll mn = min(h, l); ll mx = max(h, l);
    vector<ll> a(n); inarr(a, n);
    for (ll i = 0; i < n; i++) {
        if(a[i] <= mn) cnt1++;
        else if(a[i] <= mx) cnt2++;
    }
    
    if(cnt1 >= cnt2) cout << cnt2 + (cnt1 - cnt2)/2 << endl;
    else cout << cnt1 << endl;
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