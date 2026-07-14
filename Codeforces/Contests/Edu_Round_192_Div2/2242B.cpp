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

    vector<ll> pre(n, 0);
    for (ll i = 0; i < n; i++) {
        if(a[i] == 1 || a[i] == 2) pre[i] = 1;
        else pre[i] = -1;
        if(i) pre[i] += pre[i - 1];
    }
    
    vector<bool> chk(n, false);
    ll mx = -1e18;
    for (ll i = n - 2; i >= 1; i--) {
        mx = max(mx, pre[i]);
        if(mx >= pre[i - 1]) chk[i] = true;
    }
    if (n > 0 && mx > 0) chk[0] = true;
    
    ll curr = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i] == 1) curr++;
        else curr--;
        if(curr >= 0 && chk[i + 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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