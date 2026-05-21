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
    vector<ll> p(n); inarr(p, n);
    vector<ll> d(n); inarr(d, n);

    // finds pos_hit and t_hit where it will hit a red light
    auto f = [&] (ll x, ll t, bool fwd) {
        ll xmn = 2e15; ll idx = -1; ll xmx = 0;
        for (ll i = 0; i < n; i++) {
            if(fwd && p[i] > x) {
                if((p[i] - x + t - d[i] + 2 * k) % k == 0) {
                    if(xmn > p[i]) {
                        xmn = p[i];
                        idx = i;
                    }
                }
            }
            else if(!fwd && p[i] < x) {
                if((x - p[i] + t - d[i] + 2 * k) % k == 0) {
                    if(xmx < p[i]) {
                        xmx = p[i];
                        idx = i;
                    }
                }
            }
        }
        if(fwd) return make_tuple(xmn, t + xmn - x, idx, !fwd);
        else return make_tuple(xmx, t + x - xmx, idx, !fwd);
    };

    auto rep = [&] (ll x) {
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        ll curr = x, t = 0; bool dir = true;

        for (ll i = 0; i < n; i++) {
            if (p[i] == x && d[i] == 0) { 
                dir = false; 
                break;
            }
        }

        for (ll i = 0; i <= 2 * n; i++) {
            auto [ncurr, nt, id, dr] = f(curr, t, dir);
            if(id == -1) return false;
            if (vis[id][dir]) return true;
            vis[id][dir] = true;
            curr = ncurr; t = nt; dir = dr;
        }
        return false;
    };

    ll q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        if(!rep(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
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