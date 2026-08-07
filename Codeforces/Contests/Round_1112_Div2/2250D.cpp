#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll MOD = 998244353;

using namespace std;
vector<ll> fact(1e6 + 5, 1);

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n-1); inarr(a, n - 1);

    // saved copy
    vector<ll> c = a;

    // cnt of expected runs
    ll cnt = 1;
    for (ll i = 0; i < n - 2; i++) {
        cnt += (a[i] != a[i + 1]);
    }
    
    // val and cnt of runs in given array
    vector<pll> b; sort(all(a));
    ll idx = 0;
    while(idx < n - 1) {
        ll cnt = 1; ll val = a[idx];
        while(idx < n - 2 && a[idx] == a[idx + 1]) {cnt++; idx++;}
        b.push_back({val, cnt});
        idx++;
    }
    
    if(b.size() != cnt || a[n - 2] != n - 1) {
        cout << 0 << endl;
        return;
    }

    c.erase(unique(all(c)), c.end());
    for (ll i = 0; i < c.size(); i++) {
        if(c[i] == n - 1) break;
        if(c[i] > c[i + 1]) {
            cout << 0 << endl;
            return;
        }
    }
    for (ll i = 0; i < c.size(); i++) {
        if(c[c.size() - i - 1] == n - 1) break; 
        if(c[c.size() - i - 1] > c[c.size() - i - 2]) { 
            cout << 0 << endl;
            return;
        }
    }
    
    ll ans = 1;
    ll taken = 0;
    for(auto [val, ct] : b) {
        taken++;
        ll space = ct - 1;
        ll allowed = val - taken;
        if(allowed < space) { 
            ans = 0; 
            break; 
        }
        ll poss = 1;
        for(ll i = 0; i < space; i++) {
            poss = (poss * (allowed - i)) % MOD;
        }
        // poss = (poss * fact[space]) % MOD;
        ans = (ans * poss) % MOD;
        taken += ct - 1;
    }
    ans = (2 * ans) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    for (ll i = 2; i <= 1e6; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}