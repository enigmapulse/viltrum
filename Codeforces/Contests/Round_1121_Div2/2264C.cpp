#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    sort(all(a)); 
    
    ll dp = 0, ways = 1;
    ll sm = a[n - 1] % MOD;
    for (ll i = n - 2; i >= 0; --i) {
        ll choices = n - 1 - i; 
        ll diff = (sm - (choices * a[i]) % MOD + MOD) % MOD;
        ll ndp = (dp * choices) % MOD;
        ndp = (ndp + diff * ways) % MOD;
        dp = ndp;
        ways = (ways * choices) % MOD;
        sm = (sm + a[i]) % MOD;
    }
    cout << dp << endl;
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