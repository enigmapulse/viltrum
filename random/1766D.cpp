#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define INF 1e18

using namespace std;

bool multipleTests = true;

const ll MAXN = 10000005;
ll spf[MAXN];

void sieve() {
    spf[1] = 1LL;
    for (ll i = 2; i < MAXN; i++) spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

set<ll> primeDiv(ll n) {
    set<ll> ret;
    while (n != 1) {
        ret.insert(spf[n]);
        n /= spf[n];
    }
    return ret;
}

void solve() {
    ll x, y; cin >> x >> y;

    if (x == y) {
        cout << 0 << endl;
        return;
    }

    ll d = abs(y - x);
    set<ll> s = primeDiv(d);

    ll ans = INF;
    for (auto p : s) {
        ans = min(ans, (p - x % p) % p);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; sieve();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}