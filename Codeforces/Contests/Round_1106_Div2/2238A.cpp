#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);

    ll cost = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] - b[i] < 0) {cost = 1e15; break;}
        cost += a[i] - b[i];
    }
    
    ll cost2 = k;
    sort(all(a)); sort(all(b));
    for (ll i = 0; i < n; i++) {
        if(a[i] - b[i] < 0) {cost2 = 1e15; break;}
        cost2 += a[i] - b[i];
    }
    cost = min(cost, cost2);
    if(cost == 1e15) cout << -1 << endl;
    else cout << cost << endl;
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