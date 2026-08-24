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

    multiset<ll> ms;
    vector<vector<string>> adj(11);
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        // reverse(all(s));
        // while(s.back() == '0') s.pop_back();
        // reverse(all(s));
        adj[s.size()].push_back(s);
        ms.insert(stoll(s));
    }
    
    vector<string> best; ll cnt = 0;
    for (ll sz = 10; sz >= 0; sz--) {
        sort(all(adj[sz]), greater());
        for(auto x : adj[sz]) {
            best.push_back(x);
            ms.erase(stoll(x));
            cnt++;
            if(cnt == k) break;
        }
        if(cnt == k) break;
    }
    sort(all(best), greater());

    auto it = ms.end(); 
    auto ut = prev(it);
    ll val = *ut;
    if(stoll(best[0]) < val) best[0] = to_string(val);

    // ll mx = stoll(best[0]), idx = 0;
    // for (ll i = 1; i < best.size(); i++) {
    //     if(stoll(best[i]) > mx) {
    //         mx = stoll(best[i]);
    //         idx = i;
    //     }
    // }
    // if(idx != 0) swap(best[idx], best[0]);
    best[0] = to_string(stoll(best[0]));

    for(auto x : best) cout << x;
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