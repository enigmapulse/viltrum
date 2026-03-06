#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; 
    vector<ll> a(n + 1); inarr(a, n);

    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        ll val = a[i] - (i % a[i]);
        for (ll j = val; j <= n; j += a[i]) {
            if(j <= i) continue;
            if(a[i] * a[j] == i + j) cnt++;
        }
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