#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, target; cin >> n >> target;
    map<ll, ll> dist;
    queue<ll> q; q.push(n); dist[n] = 0;
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        if(v == target) {
            cout << dist[v] << endl;
            return;
        }
        if(!dist.contains(v/2)) {
            q.push(v/2); 
            dist[v/2] = dist[v] + 1;
        }
        if(!dist.contains((v + 1)/2)) {
            q.push((v + 1)/2); 
            dist[(v + 1)/2] = dist[v] + 1;
        }
    }

    cout << -1 << endl;
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