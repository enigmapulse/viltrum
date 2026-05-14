#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) {
        string s; cin >> s;
        if(s == "?") a[i] = -1;
        else a[i] = stoll(s);
    }
 
    ll l = 0,r = 1e14;
    for (ll i = 1; i <= n; i++) {
        if(a[i] == -1) continue;
        ll start = max((a[i] - 1) * i + 1, 0ll);
        ll end = a[i] * i;
 
        l = max(l, start);
        r = min(r, end);
    }
    
    cout << l << endl;
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