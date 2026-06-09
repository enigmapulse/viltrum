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
    if(n == 2) {
        cout << max(a[0], a[1]) << " " << min(a[0], a[1]) << endl;
        return;
    }

    sort(all(a));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(j == i) continue;
            ll x = max(a[i], a[j]), y = min(a[i], a[j]);
            vector<ll> b = {x, y}; 
            while(b.size() != n) {
                if(y == 0) break;
                x = x % y;
                swap(x, y);
                b.push_back(y);
            }
            sort(all(b));
            if(a == b) {
                cout << max(a[i], a[j]) << " " << min(a[i], a[j]) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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