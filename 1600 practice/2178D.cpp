#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (ll _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(n); 
    for(ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }

    if (m == n) {
        cout << "-1" << endl;
        return;
    }

    sort(all(a));
    vector<pair<ll, ll>> ops;

    if(m == 0) {
        vector<bool> use(n, false);
        use[n-2] = true; 
        
        ll cur = 0; 
        ll hi = a[n-1].first;

        for(ll i = n - 3; i >= 0; --i) {
            if (cur + a[i].first < hi) {
                cur += a[i].first;
                use[i] = true;
            }
        }

        if (cur + a[n-2].first < hi) {
            cout << "-1" << endl;
        } else {
            cout << n - 1 << endl; 
            for(ll i = 0; i <= n - 2; ++i) {
                if (use[i]) {
                    cout << a[i].second << " " << a[n-1].second << endl;
                } else {
                    cout << a[i].second << " " << a[i+1].second << endl;
                }
            }
        }
        return;
    }

    if (n < 2 * m) {
        cout << "-1" << endl;
        return;
    }

    ll cnt = n - 2 * m;
    if (cnt > 0) {
        for(ll i = 0; i < cnt - 1; ++i) {
            ops.push_back({a[i].second, a[i+1].second});
        }
        ops.push_back({a[cnt - 1].second, a[cnt].second});
    }

    for(ll i = 0; i < m; ++i) {
        ll v = cnt + i;
        ll s = cnt + m + i;
        ops.push_back({a[s].second, a[v].second});
    }

    cout << ops.size() << endl;
    for(auto op : ops) {
        cout << op.first << " " << op.second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}