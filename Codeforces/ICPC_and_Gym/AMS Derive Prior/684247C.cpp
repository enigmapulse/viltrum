#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll k; cin >> k;

    map<ll, ll> d; bool chk = true;
    map<ll, ll> n;
    for (ll i = 0; i < k; i++) {
        ll u, v; cin >> u >> v;
        n[u] = v;
        if(v & 1) chk = false;
    }

    ll sm  = 0;
    ll m; cin >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        d[u] = v; sm += v;
    }
    // cerr << sm << endl;

    if(!chk) {
        cout << "Alice" << endl;
        return;
    }
    else {
        if(sm & 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
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