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

    vector<ll> suff(n, 0); 
    suff[n - 1] = -a[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        suff[i] = -a[i] + suff[i + 1];
    }
    
    vector<ll> pre(n, 0); 
    pre[0] = a[0];
    for (ll i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + abs(a[i]);
    }
    
    ll ans = suff[1]; 

    for (ll i = 1; i < n; i++) {
        ll current = pre[i - 1]; 
        if (i + 1 < n) {
            current += suff[i + 1]; 
        }
        ans = max(ans, current);
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