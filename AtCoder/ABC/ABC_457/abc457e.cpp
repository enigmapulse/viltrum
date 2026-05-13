#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1), b(n + 1);
    multiset<pair<ll, ll>> ms;
    for (ll i = 0; i < m; i++) {
        ll l, r; cin >> l >> r;
        a[l].push_back(r - l + 1);
        b[r].push_back(r - l + 1);
        ms.insert({l, r});
    }
    
    for (ll i = 1; i <= n; i++) {
        if(!a[i].empty()) sort(all(a[i]));
        if(!b[i].empty()) sort(all(b[i]));
    }
    
    ll q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        auto it = upper_bound(all(a[l]), r - l + 1);
        if(it == a[l].begin()) {
            cout << "No" << endl;
        } 
        else {
            it = prev(it);
            if(*it != r - l + 1) {
                ll req_min = r - l + 1 - *it;
                auto ut = lower_bound(all(b[r]), req_min);
                if(ut == b[r].end() || *ut > r - l + 1) {
                    cout << "No" << endl;
                }
                else cout << "Yes" << endl;
            }
            else {
                auto wt = ms.find({l, r});
                ms.erase(wt);
                auto ut = ms.lower_bound({l, -1});
                if(ut != ms.end() && ut -> second <= r) cout << "Yes" << endl;
                else cout << "No" << endl;
                ms.insert({l, r});
            }
        }
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