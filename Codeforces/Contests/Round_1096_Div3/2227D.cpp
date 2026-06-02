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
    n = 2 * n;
    vector<ll> a(n); inarr(a, n);

    // odd length checks
    vector<ll> idx;
    for (ll i = 0; i < n; i++) {
        if(a[i] == 0) idx.push_back(i);
    }
    
    ll ans = 1;
    for (ll i = 0; i < 2; i++) {
        ll id = idx[i]; 
        set<ll> mex = {0};
        for (ll i = 0; i < n; i++) {
            if(id - i - 1 >= 0 && id + i + 1 < n && a[id - i - 1] == a[id + i + 1]) mex.insert(a[id - i - 1]);
            else break;
        }
        for (ll i = 0; i <= n; i++) {
            if(mex.find(i) == mex.end()) {ans = max(ans, i); break;}
        }
    }
    
    bool chk = true;
    set<ll> mex = {0};
    for (ll i = idx[0]; i <= idx[1]; i++) {
        chk &= (a[i] == a[idx[0] + idx[1] - i]);
        mex.insert(a[i]);
    }
    if(!chk) cout << ans << endl;
    else {
        for (ll i = 0; i < n; i++) {
            if(idx[0] - i - 1 >= 0 && idx[1] + i + 1 < n && a[idx[0] - i - 1] == a[idx[1] + i + 1]) mex.insert(a[idx[0] - i - 1]);
            else break;
        }
        for (ll i = 0; i <= n; i++) {
            if(mex.find(i) == mex.end()) {ans = max(ans, i); break;}
        }
        cout << ans << endl;
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