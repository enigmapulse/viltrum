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

    if(n == 1) {
        cout << a[0] << endl;
        return;
    }

    vector<ll> sufmin(n); sufmin[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--) {
        sufmin[i] = min(sufmin[i + 1], a[i]);
    }
    
    ll mn = 1e12;
    vector<ll> keep, moved;
    for (ll i = 0; i < n; i++) {
        if(sufmin[i] < a[i] || mn < a[i]) {
            moved.push_back(a[i] + 1);
            mn = min(mn, a[i] + 1);
        }
        else keep.push_back(a[i]);
    }

    sort(all(moved));

    for(auto x : keep) cout << x << " ";
    for(auto x : moved) cout << x << " ";
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