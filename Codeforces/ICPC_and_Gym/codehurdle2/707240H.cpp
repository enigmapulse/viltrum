#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> p(n + 1, 0), a(n + 1, 0); 
    inarr(a, n);
    for (ll i = 2; i <= n; i++) cin >> p[i];

    vector<vector<ll>> child(n + 1);
    for(ll idx = 1; idx <= n; idx++) {
        child[p[idx]].push_back(idx);
    }
    
    vector<ll> cur = a; 
    vector<ll> val;

    auto chk = [&] (ll x) -> bool {
        ll cuts = 0;
        for(ll i = 1; i <= n; i++) {
            cur[i] = a[i];
        }

        for (ll par = n; par >= 1; par--) {
            ll curr = a[par];
            ll lim = x - curr;
            val.clear();
            for(auto ch : child[par]) {
                val.push_back(cur[ch]);
            }
            sort(all(val));
            for (ll i = 0; i < val.size(); i++) {
                if(lim < val[i]) {
                    cuts += val.size() - i;
                    break;
                }
                else {
                    lim -= val[i];
                    curr += val[i];
                }
            }
            cur[par] = curr;
        }
        return (cuts <= k);
    };

    ll lo = *max_element(all(a)), hi = accumulate(all(a), 0ll);
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
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