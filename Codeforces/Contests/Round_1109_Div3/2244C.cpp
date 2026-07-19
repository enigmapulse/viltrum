#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vector<ll> p(n); inarr(p, n);
    ll g = gcd(x, y);
    vector<bool> vis(n, false);
    for (ll i = 0; i < n; i++) {
        if(vis[i]) continue;
        vector<ll> chunk;
        for (ll j = i; j < n; j += g) {
            chunk.push_back(p[j]);
        }
        sort(all(chunk));
        for (ll j = i; j < n; j += g) {
            p[j] = chunk[(j - i) / g];
            vis[j] = true;
        }
    }
    
    vector<ll> temp = p; sort(all(temp));
    if(temp == p) cout << "YES" << endl;
    else cout << "NO" << endl;
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