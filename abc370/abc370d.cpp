#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    ll q; cin >> q;

    vector<set<ll>> rows(n + 1);
    for (ll i = 1; i <= n; i++) {
        set<ll> s;
        for (ll j = 1; j <= m; j++) s.insert(j);
        rows[i] = s;
    }

    vector<set<ll>> cols(m + 1);
    for (ll i = 1; i <= m; i++) {
        set<ll> t;
        for (ll j = 1; j <= n; j++) t.insert(j);
        cols[i] = t;
    }
    
    ll cnt = 0;

    auto del = [&] (ll i, ll j) {
        if(rows[i].erase(j)) {
            cols[j].erase(i);
            cnt++;
        }
    };

    while(q--) {
        ll i, j; cin >> i >> j;
        if(rows[i].find(j) != rows[i].end()) {
            del(i, j);
            continue;
        }

        // deleting cells from that row
        auto it = rows[i].lower_bound(j);
        if(it != rows[i].begin()) {
            auto ut = it; --ut;
            del(i, *ut);
        }
        it = rows[i].lower_bound(j);
        if(it != rows[i].end()) del(i, *it);

        // deleting cells from that col
        auto wt = cols[j].lower_bound(i);
        if(wt != cols[j].begin()) {
            auto ut = wt; --ut;
            del(*ut, j);
        }
        wt = cols[j].lower_bound(i);
        if(wt != cols[j].end()) del(*wt, j);
    }
    
    cout << n*m - cnt << endl;
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