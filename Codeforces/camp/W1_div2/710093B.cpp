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
    vector<ll> a(n); inarr(a, n);
    for(auto& x : a) x = x % m;

    vector<ll> left, right;
    for (ll i = 0; i < n / 2; i++) {
        left.push_back(a[i]);
    }
    for (ll i = n/ 2; i < n; i++) {
        right.push_back(a[i]);
    }

    set<ll> st1, st2;
    for (ll mask = 0; mask < (1 << left.size()); mask++) {
        ll curr = 0;
        for (ll i = 0; i < left.size(); i++) {
            if((mask >> i) & 1) curr = (curr + left[i]) % m;
        }
        st1.insert(curr);
    }
    for (ll mask = 0; mask < (1 << right.size()); mask++) {
        ll curr = 0;
        for (ll i = 0; i < right.size(); i++) {
            if((mask >> i) & 1) curr = (curr + right[i]) % m;
        }
        st2.insert(curr);
    }

    ll mx = 0;
    for(auto x : st1) {
        mx = max(mx, (x + *st2.rbegin()) % m);
        auto it = st2.lower_bound(m - x);
        it = prev(it);
        mx = max(mx, x + *it);
    }

    cout << mx << endl;
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