#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);
    sort(all(a)); a.push_back(1e12);

    ll mx_len = 0, curr = 1;
    for (ll i = 1; i <= n; i++) {
        if(a[i] == a[i - 1] + 1) curr++;
        else {
            mx_len = max(mx_len, curr);
            curr = 1;
        }
    }
    
    ll cnt = 0; curr = 1;
    for (ll i = 1; i <= n; i++) {
        if(a[i] == a[i - 1] + 1) curr++;
        else {
            if(curr == mx_len) cnt++;
            curr = 1;
        }
    }

    ll rem = n - mx_len;
    ll ans = binpow(2, mx_len - 1);
    for (ll i = 1; i <= rem; i++) ans = (ans * i) % MOD;
    ans = (ans * cnt) % MOD;

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