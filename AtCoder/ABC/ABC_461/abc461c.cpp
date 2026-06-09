#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll m, k, n; cin >> n >> k >> m;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++) {
        ll c, v; cin >> c >> v;
        a[i] = {v, c};
    }
    sort(all(a), greater());
    ll cost = 0;
    vector<ll> rem; ll cnt = 0;
    vector<bool> vis(n + 1, false);
    for (ll i = 0; i < n; i++) {
        if(cnt == m || vis[a[i].second]) {
            rem.push_back(a[i].first);
            continue;
        }
        vis[a[i].second] = true;
        cnt++;
        cost += a[i].first;
    }
    sort(all(rem), greater());
    for (ll i = 0; i < rem.size(); i++) {
        if(cnt == k) break;
        cost += rem[i]; cnt++;
    }
    cout << cost << endl;   
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