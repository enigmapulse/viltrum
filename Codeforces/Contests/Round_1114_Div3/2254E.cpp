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
    multiset<ll> s(all(a));

    ll mn_pos = 1e12;
    for (ll i = 0; i < n; i++) {
        if(a[i] > 0) mn_pos = min(mn_pos, a[i]);
    }

    if(mn_pos == 1e12) {
        cout << -1 << endl;
        return;
    }
    
    s.erase(s.find(mn_pos));
    ll curr = mn_pos;
    vector<ll> ans;
    
    while(!s.empty()) {
        ans.push_back(curr);
        ll pos = 1 - curr;
        auto it = s.lower_bound(pos);
        if(it == s.end()) {
            cout << -1 << endl;
            return;
        }
        curr = curr + (*it);
        s.erase(it);
    }
    ans.push_back(curr);

    if(ans.size() != n) {
        cout << -1 << endl;
        return;
    }

    for(auto x : ans) cout << x << " ";
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