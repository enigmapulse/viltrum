#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n + 1), q(n + 1);
    inarr(p, n); inarr(q, n);

    vector<ll> qinv(n + 1);
    for (ll i = 1; i <= n; i++) {
        qinv[q[i]] = i;
    }

    for (ll i = 1; i <= n; i++) {
        cout << q[p[qinv[i]]] << " ";
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