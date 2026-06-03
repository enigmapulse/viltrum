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
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];

    ll tot = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) tot += (grid[i][j] - '0');
    }
    
    vector<ll> cnt(n, 0);
    for (ll i = 0; i < n; i++) {
        ll curr = 0;
        for (ll j = 0; j < n; j++) curr += grid[(i + j) % n][j % n] - '0';
        cnt[i] = curr;
    }
    
    ll mn = 1e15;
    for (ll i = 0; i < n; i++) {
        mn = min(mn, (n - cnt[i]) + (tot - cnt[i]));
    }
    cout << mn << endl;
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