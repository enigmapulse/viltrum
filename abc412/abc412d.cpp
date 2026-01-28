#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1, vector<ll> (n + 1, 0));
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u][v] = 1; adj[v][u] = 1;
    }
    ll ans = 1e12;
    
    {
        // case 1 : one cycle
        vector<ll> perm(n); iota(all(perm), 1);

        do {
            ll cnt = 0;
            for (ll i = 0; i < n; i++) {
                ll u = perm[i];
                ll nxt = perm[(i + 1) % n], prev = perm[(i - 1 + n) % n];
                for(ll j = 1; j <= n; j++) {
                    if(adj[u][j] && (j != nxt && j != prev)) cnt++;
                    if(!adj[u][j] && (j == nxt || j == prev)) cnt++;
                }
            }
            ans  = min(ans, cnt);

        } while(next_permutation(all(perm)));
    }

    {
        // case 2 : two cycle
        vector<ll> zeros, ones;
        for (ll i = 1; i < (1 << n) - 1; i++) {
            zeros.clear(); ones.clear();
            for (ll bit = 0; bit < n; bit++) {
                if((i >> bit) & 1) ones.push_back(bit + 1);
                else zeros.push_back(bit + 1);
            }

            if(zeros.size() < 3 || ones.size() < 3) continue;

            do {
                ll sz = zeros.size(); ll cnt = 0;
                for (ll i = 0; i < sz; i++) {
                    ll u = zeros[i];
                    ll nxt = zeros[(i + 1) % sz], prev = zeros[(i - 1 + sz) % sz];
                    for(ll j = 1; j <= n; j++) {
                        if(adj[u][j] && (j != nxt && j != prev)) cnt++;
                        if(!adj[u][j] && (j == nxt || j == prev)) cnt++;
                    }
                }

                do {
                    ll s = ones.size(); ll ct = 0;

                    for (ll i = 0; i < s; i++) {
                        ll u = ones[i];
                        ll nxt = ones[(i + 1) % s], prev = ones[(i - 1 + s) % s];
                        for(ll j = 1; j <= n; j++) {
                            if(adj[u][j] && (j != nxt && j != prev)) ct++;
                            if(!adj[u][j] && (j == nxt || j == prev)) ct++;
                        }
                    }
                    ans = min(ans, cnt + ct);

                } while(next_permutation(all(ones)));

            } while(next_permutation(all(zeros)));
        }
    }

    cout << ans / 2 << endl;
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