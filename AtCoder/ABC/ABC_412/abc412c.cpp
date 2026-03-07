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
    sort(a.begin() + 1, a.end() - 1);

    vector<ll> ans; ans.push_back(a[n - 1]);
    if(n == 2) {
        if(2*a[0] >= a[1]) cout << 2 << endl;
        else cout << -1 << endl;
        return; 
    }

    for(ll i = 0; i < n; ++i) {
        ll b = ans.back();
        auto it = lower_bound(a.begin() + 1, a.end() - 1, (b + 1)/2);
        if(2*a[0] >= b) {
            ans.push_back(a[0]);
            break;
        }
        if(it == a.end() - 1) break;
        ans.push_back(*it);
    }

    if(ans.size() == 1 || ans.back() != a[0]) cout << -1 << endl;
    else cout << ans.size() << endl;
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