#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define plp pair<ll, pll>
const ll INF = 1e15;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> h(n + 1); inarr(h, n);
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto chk = [&](ll x) {
        if (h[1] > x) return false;
        vector<ll> dist(n + 1, INF);
        queue<ll> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            if (dist[v] == k - 1) continue;
            for (ll ch : adj[v]) {
                if (h[ch] <= x && dist[ch] == INF) {
                    dist[ch] = dist[v] + 1;
                    q.push(ch);
                }
            }
        }
        return dist[n] < k;
    };

    ll mx = *max_element(all(h));
    ll lo = h[1], hi = mx + 1;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }

    if(lo == mx + 1) cout << -1 << endl;
    else cout << lo << endl;
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