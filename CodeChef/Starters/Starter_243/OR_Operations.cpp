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

    ll cnt = 0; ll tot = 0;
    for (ll i = 0; i < n; i++) tot |= a[i];

    if(tot == 0) {
        cout << 0 << endl;
        return;
    }
    
    ll idx = 0;
    while(idx < n) {
        ll sz = 0, cur = 0;
        while(idx < n && cur != tot) {
            cur = cur | a[idx];
            sz++; idx++;
        } 
        cnt += sz - 1;
        if(cur != tot) cnt++;
    }
    cout << cnt << endl;
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