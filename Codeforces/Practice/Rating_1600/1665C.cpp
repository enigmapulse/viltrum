#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 2; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; 
    vector<ll> a(n + 1); a[1] = 1; inarr(a, n);

    vector<vector<ll>> adj(n + 1);
    for (ll i = 1; i <= n; i++) adj[a[i]].push_back(i);

    vector<ll> layers(n + 1, 0);
    for (ll i = 1; i <= n; i++) layers[i] = adj[i].size();
    
    ll ops = 1;
    for (ll i = 0; i < n; i++) {
        if(layers[i] > 0) {
            ops++; layers[i]--;
        }
    }
    ll levy = ops - 1;
    for (ll i = 0; i < n; i++) {
        ll rem = min(levy, layers[i]);
        levy -= rem; layers[i] -= rem; 
        ops += (layers[i] + 1) / 2;
    }
    cout << ops << endl;
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