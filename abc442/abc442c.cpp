#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

ll f (ll n) {
    if(n < 3) return 0;
    ll ans = n;
    ans = ans * (n - 1);
    ans = ans * (n - 2);
    ans = ans / 6;
    return ans;
}

void solve() {
    ll n, m; cin >> n >> m;

    vector<ll> deg(n + 1);
    while(m--) {
        ll u, v; cin >> u >>v;
        deg[u]++; deg[v]++;
    }

    for (ll i = 1; i <= n; i++) {
        cout << f(n - deg[i] - 1) << " ";
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