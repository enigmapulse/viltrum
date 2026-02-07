#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);
    sort(all(a));

    cout << ceil(log2(n)) << endl;

    function<void(ll, ll, vector<ll>&)> recur = [&] (ll l, ll r, vector<ll>& a) {
        for (ll i = l; i <= r; i++) {
            a[i]++;
        }
        if(l == r) return;
        recur(l, (l + r)/ 2, a);
        recur((l + r)/ 2 + 1, r, a);
    };

    vector<pair<ll, ll>> dp(n, {0, 0});
    for (ll i = n - 1; i >= 0; i--) {
        vector<ll> depth(n, 0);
        recur(0, i, depth);
        for(auto x : depth) cout << x << " ";
        cout << endl;
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