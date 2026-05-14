#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    set<pair<ll, ll>> s;
    for (ll i = 0; i < n; i++) {
        s.insert({a[i], i});
    }
    ll cnt = 0;
    ll end = n;
    while(!s.empty()) {
        auto it = s.end(); --it;
        auto [val, idx] = *it;
        cnt++;
        for (ll i = idx; i < end; i++) {
            s.erase({a[i], i});
        }
        end = idx;
    }

    cout << cnt << endl;
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