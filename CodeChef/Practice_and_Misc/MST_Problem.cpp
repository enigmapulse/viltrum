#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;

    ll lo = (n * (n - 1))  / 2;
    ll hi = ((n - 1) * ((n - 1) * (n - 1) + 5)) / 6;

    if(k < lo || k > hi) {
        cout << -1 << endl;
        return;
    }

    vector<vector<ll>> adj(n, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) adj[0][i] = i;

    ll curr = lo, idx = n - 1;
    while(curr < k) {
        ll mx = 1 + (idx * (idx - 1)) / 2;
        if(curr + mx - idx <= k) {
            curr += mx - idx;
            adj[0][idx] = mx;
            idx--;
        }
        else {
            adj[0][idx] += k - curr;
            curr = k;
        }
    }

    set<ll> s;
    for (ll i = 1; i <= (n * (n - 1)) / 2; i++) s.insert(i);
    for (ll i = 1; i < n; i++) {
        s.erase(adj[0][i]);
    }
    
    for (ll i = 1; i < n; i++) {
        for (ll j = 1; j < i; j++) {
            adj[i][j] = * s.begin();
            s.erase(s.begin());
        }
    }
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(i != j && adj[i][j] == 0) adj[i][j] = adj[j][i];
            cout << adj[i][j] << " ";
        }
        cout << endl;
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