#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MAX = 3e5;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> ans(MAX + 1, 0);
    for(auto x : a) ans[x - 1] += 1;
    for (ll i = MAX - 2; i >= 0; i--) ans[i] += ans[i + 1];

    for (ll i = 0; i < MAX; i++) {
        ll q = ans[i] / 10;
        ll r = ans[i] % 10;
        ans[i] = r;
        ans[i + 1] += q;
    }
    
    bool chk = false;
    for (ll i = MAX; i >= 0; i--) {
        if(ans[i] != 0) {cout << ans[i]; chk = true;}
        else if(chk) cout << ans[i];
    }
    cout << endl;
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