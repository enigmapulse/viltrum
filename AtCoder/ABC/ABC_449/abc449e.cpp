#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> freq; for(auto x : a) freq[x]++; 
    map<ll, set<ll>> mp; // freq and nums with that same freq
    for(auto [x, f]: freq) {
        mp[f].insert(x);
    }

    ll q; cin >> q;
    vector<ll> queries(q); inarr(queries, q);
    vector<ll> comp = queries; sort(all(comp));
    vector<ll> ans(q, 0);

    ll idx = 0;
    for(auto x : comp) {
        if(x <= n) ans[idx] = a[x - 1];
        else {
            
        }

        idx++;
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