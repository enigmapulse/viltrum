#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n); inarr(a, n); sort(all(a));
    ll curr = 0; ll cnt = 0;
    for (ll i = k - 1; i >= 0; i--) {
        curr += a[i]; cnt++;
        if(curr >= x) {
            break;
        }
    }
    
    if(curr >= x) cout << cnt + n - k << endl;
    else cout << -1 << endl;
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