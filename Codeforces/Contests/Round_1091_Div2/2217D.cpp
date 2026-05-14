#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> b(n); inarr(b, n);
    vector<ll> c(k); inarr(c, k);

    sort(all(c));

    vector<ll> cnt; ll prev = 1; 

    for (ll cut : c) {
        ll curr = 0;
        for (ll i = prev - 1; i < cut - 1; i++) {
            if (b[i] != b[i + 1]) curr++;
        }
        cnt.push_back(curr);
        prev = cut + 1;
    }

    ll curr = 0;
    for (ll i = prev - 1; i < n - 1; i++) {
        if (b[i] != b[i + 1]) curr++;
    }
    cnt.push_back(curr);

    for (auto x : cnt) cout << x << " ";
    cout << '\n';
    // ll ans = 0;
    // if(ans & 1) cout << ans + 1 << endl;
    // else cout << ans << endl;
    
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