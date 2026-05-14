#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k, w; cin >> n >> m >> k >> w;
    vector<ll> c1(n), c2(m); inarr(c1, n); inarr(c2, m);

    vector<ll> pos1(100 * n + 1, 0), pos2(100 * m + 1, 0);
    pos1[0] = pos2[0] = 1;

    for (ll j = 0; j < n; j++) {
        ll coin = c1[j];
        for (ll i = pos1.size() - 1; i >= coin; i--) {
            pos1[i] = (pos1[i] + pos1[i - coin]) % MOD;
        }
    }

    for (ll j = 0; j < m; j++) {
        ll coin = c2[j];
        for (ll i = pos2.size() - 1; i >= coin; i--) {
            pos2[i] = (pos2[i] + pos2[i - coin]) % MOD;
        }
    }
    
    ll cnt = 0;
    for (ll i = 0; i < pos1.size(); i++) {
        ll req = w - i;
        if(req >= 0 && req < pos2.size() && pos2[req] > 0 && abs(i - req) <= k) cnt += (pos1[i] * pos2[req]) % MOD;
    }
    
    cout << cnt % MOD << endl;
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