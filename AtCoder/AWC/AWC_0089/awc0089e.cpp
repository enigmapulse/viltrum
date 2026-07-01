#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define ppl pair<pll, ll>
#define tlll tuple<ll, ll, ll>
const ll INF = 1e6;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<tlll> ins; vector<ll> diff(m - k + 3, 0);
    for (ll i = 1; i <= m; i++) {
        ll s, e; cin >> s >> e;
        ins.push_back({s, 0, i});
        ins.push_back({e + 1, 1, i});
    }
    sort(all(ins)); 

    set<ll> curr; ll last = 0, tot = 0, i = 0;
    while (i < ins.size()) {
        auto pt = get<0>(ins[i]);
        ll len = pt - last;

        if(len > 0 && !curr.empty()) {
            tot += len;
            auto it = *curr.begin();
            auto ut = *curr.rbegin();
            it = min(it, m - k + 1);
            ut = max(1ll, ut - k + 1);
            if(ut <= it) {
                diff[it + 1] -= pt - last;
                diff[ut] += pt - last;
            }
        }

        last = pt;
        while(i < ins.size() && get<0>(ins[i]) == pt) {
            auto [_ , state, idx] = ins[i];
            if(state == 0) curr.insert(idx);
            else curr.erase(idx);
            i++;
        }
    }
    for (ll i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];
    
    cout << tot - *min_element(diff.begin() + 1, diff.begin() + m - k + 2) << endl;
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