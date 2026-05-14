#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k, p, q; cin >> n >> k >> p >> q;
    vector<ll> a(n); inarr(a, n);

    auto B = [&] (ll x) {return (x % p);};
    auto C = [&] (ll x) {return (x % q) % p;};

    vector<ll> b(n), c(n), better(n);;
    for (ll i = 0; i < n; i++) {
        b[i] = B(a[i]); c[i] = C(a[i]);
        better[i] = min(b[i], c[i]);
        if(i != 0) {
            b[i] += b[i - 1];
            c[i] += c[i - 1];
            better[i] += better[i - 1];
        }
    }

    if(n == 1) {
        cout << min(b[0], c[0]) << endl;
        return;
    }
    
    ll sm = better[n - 1], ans = 1e16;
    for (ll start = 0; start <= n - k; start++) {
        ll end = start + k - 1;
        ll curr_sm = better[end] - (start > 0 ? better[start - 1] : 0);
        ll new_sm_B = b[end] - (start > 0 ? b[start - 1] : 0);
        ll new_sm_C = c[end] - (start > 0 ? c[start - 1] : 0);
        ans = min({ans, sm - curr_sm + new_sm_B, sm - curr_sm + new_sm_C});
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