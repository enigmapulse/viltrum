#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> a(n); inarr(a, n);

    ll mn = *min_element(a.begin() + l, a.begin() + r);
    ll idx = 0; for (ll i = l; i < r; i++) if(a[i] == mn) idx = i;
    
    vector<ll> ans;
    for (ll i = 0; i < r - l; i++) {
        ans.push_back(a[(idx - l + i) % (r - l) + l]);
    }
    
    vector<ll> lr;
    for (ll i = 0; i < l; i++) lr.push_back(a[i]);
    for (ll i = r; i < n; i++) lr.push_back(a[i]);
    
    ll pos = lr.size();
    for (ll i = 0; i < lr.size(); i++) {
        if (lr[i] > ans[0]) {
            pos = i;
            break;
        }
    }
    
    for (ll i = 0; i < pos; i++) cout << lr[i] << " ";
    for (auto x : ans) cout << x << " ";
    for (ll i = pos; i < lr.size(); i++) cout << lr[i] << " ";
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