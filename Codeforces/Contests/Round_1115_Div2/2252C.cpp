#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
ll INF = 1e18;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> val(n); inarr(val, n);

    vector<vector<ll>> adj(n, vector<ll> (m, 0));
    for (ll i = 0; i < n; i++) inarr(adj[i], m);
    
    priority_queue<ll, vector<ll>, greater<ll>> pq; ll tot = 0;
    vector<ll> cost(n, INF);
    for (ll i = n - 1; i >= 0; i--) {
        for(auto x : adj[i]) {
            pq.push(x);
            tot += x;
            if(pq.size() > m) {
                tot -= pq.top();
                pq.pop();
            }
        }
        if(tot < val[i]) {
            cost[i] = m;
            continue;
        }
        auto temp = pq;
        ll curr = 0, cnt = 0, idx = 0;
        vector<ll> best;
        while(!temp.empty()) {best.push_back(temp.top()); temp.pop();}
        reverse(all(best));
        while(curr < val[i]) {
            curr += best[idx];
            cnt++; idx++;
        }
        cost[i] = cnt;
    }
    cout << *min_element(all(cost)) << endl;
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