#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll cnt = 0;
    vector<ll> deg(n + 1, 0);
    for (ll i = 0; i < n; i++) deg[a[i]]++;
    
    queue<pll> q;
    for (ll i = 0; i < n; i++) {
        if(deg[i + 1] == 0) q.push({i + 1,  1});
    }
    
    ll mx = 0;
    while (!q.empty()) {
        auto [u, ctr] = q.front();
        q.pop();
        mx = max(mx, ctr);

        deg[a[u - 1]]--;
        if(deg[a[u - 1]] == 0) q.push({a[u - 1], ctr + 1});
    }
    
    cout << mx + 2 << endl;
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