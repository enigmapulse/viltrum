#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> prefer(n + 1, 0), cost(n + 1, 0); inarr(prefer, n); inarr(cost, n);

    vector<ll> perm(n + 1, 0);
    ll saved = 0;
    for (ll i = 1; i <= n; i++) {
        if(perm[prefer[i]] == 0) {
            perm[prefer[i]] = i;
            saved += cost[i];
        }
        else {
            if(cost[i] > cost[perm[prefer[i]]]) {
                saved += cost[i] - cost[perm[prefer[i]]];
                perm[prefer[i]] = i; 
            }
        }
    }
    
    set<ll> s;
    for(ll i = 1; i <= n; ++i) s.insert(i);
    for(ll i = 1; i <= n; ++i) {
        ll x = perm[i];
        if(x != 0) s.erase(s.find(x));
    }

    for (ll i = 1; i <= n; i++) {
        if(perm[i] == 0) {
            perm[i] = *s.begin();
            s.erase(s.begin());
        }
    }

    vector<ll> ans(n + 1);

    for (ll i = 1; i <= n; i++) {
        ll j = perm[i];
        ans[j] = i;
    }

    cout << accumulate(all(cost), 0LL) - saved << endl;
    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
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