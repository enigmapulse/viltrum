#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

const ll MAXN = 1000005;
ll spf[MAXN];

vector<ll> getDivisors(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    return divs;
}


void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll ans = 0;
    vector<ll> factors = getDivisors(n);
    for(auto f : factors) {
        ll g = 0;
        for (ll i = 0; i < n - f; i++) {
            ll diff = abs(a[i] - a[i + f]);
            g = gcd(g, diff);
            if(g == 1) break;
        }
        if(g != 1) ans++;
    }

    cout << ans << endl;
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