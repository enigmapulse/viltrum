#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll h, w; cin >> h >> w;
    ll n; cin >> n;
    vector<pair<ll, ll>> a(n);
    map<ll, set<ll>> mp;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        mp[x].insert(y);
        a[i] = {x, y};
    }
    
    ll cost = 1e15;

    {
        // case 1 : without changing lane
        ll cost1 = 0; 
        for(auto [row, S] : mp) {
            if(S.empty()) continue;
            auto it = prev(S.end());
            cost1 += 2 * (*it - 1);
        }
        cost = min(cost, cost1);
    }

    {
        // case 2 : changing lane (multiple times)

        /* calculation of shortest from both the lanes*/
        vector<ll> cost2;
        for(auto [row, S] : mp) {
            ll mx = 0;
            if(S.empty()) continue;
            auto it = S.begin(), ut = it;
            ut++;
            while(ut != S.end()) {
                mx = max(*ut - *it, mx);
                it++; ut++;
            }
            mx = max({*S.begin() - 1, mx, w - *prev(S.end())});
            cost2.push_back(2 * (w - 1 - mx));
        }

        vector<ll> save;
        /* update if simply passing the bridge is more beneficial*/
        for (ll i = 0; i < cost2.size(); i++) {
            ll c = cost2[i];
            save.push_back(c - w + 1);
        }
        sort(all(save), greater());
        ll cnt = 0; ll sm = 0;
        for (ll i = 0; i < save.size(); i++) {
            if(save[i] > 0) {cnt++; sm += save[i];}
            else break;
        }
        
        ll ch = sm;
        save.push_back(-(w - 1));
        save.push_back(-(w - 1));
        if (cnt <= 1) {
            ch = save[0] + save[1]; 
        } 
        else if (cnt & 1) {
            ch = max(sm - save[cnt - 1], sm + save[cnt]);
        }
        ll cost3 = accumulate(all(cost2), 0LL);
        cost = min(cost, cost3 - ch);
    }

    cout << cost << endl;
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