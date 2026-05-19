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

    vector<ll> uniq = {1}, fixed(n + 1, 0);
    uniq.reserve(n);

    for(ll i = 2; i <= 2 * n; ++i) {
        cout << "? " << uniq.size() + 1 << " ";
        for(auto x : uniq) {
            cout << x << " ";
        }
        cout << i << endl << flush;

        ll res; cin >> res;
        if(res == 0) uniq.push_back(i);
        else fixed[res] = i;
    }
    
    vector<ll> ans(2*n, 0);
    for (ll i = 1; i <= n; i++) {
        ans[fixed[i]] = i;
    }
    
    for(auto x : uniq) {
        cout << "? " << fixed.size() << " ";
        for(auto y : fixed) {
            if(y == 0) continue;
            cout << y << " ";
        }
        cout << x << endl << flush;

        ll res; cin >> res;
        ans[x] = res;
    }

    cout << "! ";
    for (ll i = 1; i <= 2*n; i++) cout << ans[i] << " ";
    cout << endl << flush;
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