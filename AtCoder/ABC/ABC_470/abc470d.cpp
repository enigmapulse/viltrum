#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> p1(n + 1); inarr(p1, n);
    vector<ll> p2(n + 1);
    for (ll i = 1; i <= n; i++) {
        p2[p1[i]] = i;
    }
    
    while (q--) {
        ll type, u, v;
        cin >> type;
        if(type == 2) {
            swap(p1, p2);
        }
        else {
            cin >> u >> v;
            swap(p1[u], p1[v]);
            swap(p2[p1[u]], p2[p1[v]]);
        }
    }
    for(auto x : p1) if(x) cout << x << " ";
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