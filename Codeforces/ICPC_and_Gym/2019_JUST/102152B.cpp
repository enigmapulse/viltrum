#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(m+ 1, 1);
    for (ll i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        for (ll j = l; j <= r; j++) a[j] = 0;
    }

    vector<pair<ll, ll>> c(m + 1, {-1, -1});
    ll idx = 1;
    while(idx <= m) {
        if(a[idx] == 0) {
            idx++; continue;
        }
        else {
            ll sm = 0; ll l = idx;
            while(idx <= m && a[idx] == 1) {sm++; idx++;}
            ll r = idx - 1;
            ll len = r - l + 1;
            c[len] = {l, r};
        }
    }

    pair<ll, ll> last = {-1, -1}; bool chk = false;
    for (ll i = m; i >= 1; i--) {
        if(!chk && c[i].first != -1) {
            last = c[i]; chk = true;
            continue;
        }
        if(c[i].first != -1) {
            if(last.second < c[i].second) last = c[i];
            else if(last.second == c[i].second && last.first < c[i].first) last = c[i];
        }
        c[i] = {last.second - i + 1, last.second};
    }
    
    while(k--) {
        ll x; cin >> x;
        if(c[x].first <= 0 || c[x].second <= 0) cout << -1 << " " << -1 << endl;
        else cout << c[x].first << " " << c[x].second << endl;
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