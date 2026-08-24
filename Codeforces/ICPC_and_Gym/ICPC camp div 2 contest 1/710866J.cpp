#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);

    sort(all(a), greater()); sort(all(b), greater());
    vector<ll> c(n + m); merge(all(a), all(b), c.begin(), greater());

    ll cnta = 0, cntb = 0; 
    vector<pair<ll, ll>> cnt;
    for(auto x : c) {
        if(cnta < n && x == a[cnta]) ++cnta;
        else if(cntb < m && x == b[cntb]) ++cntb;

        cnt.push_back({cnta, cntb});
    }

    for (ll i = 1; i < n; i++) a[i] += a[i - 1];
    for (ll i = 1; i < m; i++) b[i] += b[i - 1];

    while(q--) {
        ll x, y, z; cin >> x >> y >> z;

        if(z == 0) {
            cout << 0 << endl;
            continue;
        }

        auto [idxa, idxb] = cnt[z - 1];
        idxa--; idxb--;
        if(idxa >= x) {
            idxa = x - 1;
            idxb = z - x - 1;
        }
        else if(idxb >= y) {
            idxb = y - 1;
            idxa = z - y - 1;
        }
        ll ans = 0;
        if(idxa >= 0 && idxa < n) ans += a[idxa];
        if(idxb >= 0 && idxb < m) ans += b[idxb];
        cout << ans << endl;
    }
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