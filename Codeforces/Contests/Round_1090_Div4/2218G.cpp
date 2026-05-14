#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 676767677;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> b(n); inarr(b, n);

    vector<vector<ll>> adj(m); vector<ll> pre(m);
    for (ll i = 0; i < n; i++) adj[b[i]].push_back(i);
    for (ll i = 0; i < m; i++) {
        pre[i] = adj[i].size();
        if(i != 0) pre[i] += pre[i - 1];
    }
    
    ll cnt = 1;
    for (ll i = 1; i < m; i++) {
        for(auto idx : adj[i]) {
            ll left = -1, right = -1;
            if(idx > 0) left = b[idx - 1];
            if(idx < n - 1) right = b[idx + 1];

            if(left >= b[idx]) left = -1;
            if(right >= b[idx]) right = -1;
            ll val = max(left, right);

            if(left == -1 && right == -1) {
                cnt = 0; break;
            }
            else if(val == b[idx] - 1 && (left == -1 || right == -1)) cnt = (cnt * pre[val]) % MOD;
            else if(left == b[idx] - 1 && right == b[idx] - 1) cnt = (cnt * pre[val]) % MOD;
            else  {
                ll mul = (pre[b[idx] - 1] - (b[idx] > 1 ? pre[b[idx] - 2] : 0) + MOD) % MOD;
                cnt = (cnt * mul) % MOD;
            }
        }
        if(cnt == 0) break;
    }
    
    cout << cnt % MOD << endl;
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