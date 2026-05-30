#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> p(n); inarr(p, n);

    ll idx = -1;
    for (ll i = 0; i < n; i++)
    {
        if(p[i] == x) idx = i + 1;
    }
    

    ll l = 1, r = n + 1;
    while(r - l > 1) {
        ll mid = (l + r)/2;
        if(p[mid - 1] <= x) l = mid;
        else r = mid;
    }
    if(l == idx) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << min(l, idx) << " " << max(l, idx) << endl;
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