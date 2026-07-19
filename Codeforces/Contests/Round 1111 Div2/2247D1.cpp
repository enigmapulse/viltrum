#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);
    vector<ll> sorted = a; sort(all(sorted));

    auto chk = [&] (ull x) {
        ll jmp = bit_ceil(x + 1);
        vector<ll> b = a;
        for (ll i = 0; i < n; i += jmp) {
            ll k = min(i + jmp, n);
            sort(b.begin() + i, b.begin() + k);
        }
        return (sorted == b);
    };

    ll lo = 0, hi = n;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
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