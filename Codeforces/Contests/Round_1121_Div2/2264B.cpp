#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); inarr(a, n);

    ll best = LLONG_MIN;
    priority_queue<ll> pq; ll tot = 0;
    for (ll i = 0; i < n; i++) {
        if(i >= m - 1) best = max(best, m * a[i] - tot);
        pq.push(a[i]);
        tot += a[i];
        if(pq.size() >= m) {tot -= pq.top(); pq.pop();}
    }
    cout << best << endl;
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