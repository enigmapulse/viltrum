#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } return os << "}";
}
template<typename... Args> void dbg_out(Args&&... args) { ((cerr << " " << args), ...) << endl; }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> p(n - 1); inarr(p, n - 1);

    vector<ll> dp(n + 1, 0); dp[1] = 1; 
    vector<ll> dist(n + 1, 0); dist[1] = 0; 
    vector<vector<ll>> layer(n); layer[0].push_back(1);
    
    vector<vector<ll>> children(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        children[p[i]].push_back(i + 2);
    }
    
    queue<ll> q; q.push(1);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto child : children[u]) {
            if(dist[child] == 0) {
                dist[child] = dist[u] + 1;
                layer[dist[child]].push_back(child);
                q.push(child);
            }
        }
    }

    ll prev = 0;
    for(auto l : layer) {
        if(l.empty()) break;
        for(auto v : l) {
            if(v == 1 || p[v - 2] == 1) {dp[v] = 1; continue;}
            dp[v] = (prev - dp[p[v - 2]] + MOD) % MOD;
        }
        prev = 0;
        for(auto v : l) prev = (prev + dp[v]) % MOD;
    }

    dbg(dp);
    cout << (accumulate(all(dp), 0LL)) % MOD << endl;
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