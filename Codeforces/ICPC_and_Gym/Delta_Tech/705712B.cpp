#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> x(n); inarr(x, n);

    // stop[i] denotes the max poss for jmp len i
    vector<ll> stop(n + 1, m);
    ll idx = 0;
    while(idx < n) {
        ll len = 0; ll init = x[idx];
        while(idx + 1 < n && (x[idx] + 1 == x[idx + 1])) {idx++; len++;};
        stop[len + 1] = min(stop[len + 1], init - 1);
        idx++;
    }

    for (ll i = n - 1; i >= 0; i--) {
        stop[i] = min(stop[i], stop[i + 1]);
    }
    
    while(q--) {
        ll y; cin >> y;
        if(y > n) cout << m << " ";
        else cout << stop[y] << " ";
    }
    cout << endl;
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