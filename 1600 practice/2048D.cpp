#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> r(n); inarr(r, n);
    vector<ll> d(m); inarr(d, m);

    vector<ll> rank(m); ll kev = r[0];
    sort(all(r)); sort(all(d));
    for (ll i = 0; i < m; i++) {
        ll difficulty = d[i];
        if(difficulty <= kev) rank[i] = 1;
        else {
            auto it = lower_bound(all(r), difficulty);
            rank[i] = (r.end() - it) + 1;
        }
    }

    sort(all(rank), greater());

    for (ll i = 1; i <= m; i++) {
        ll rem = m % i; 
        ll sm = 0;
        for(ll j = rem; j < m; j += i) sm += rank[j];
        cout << sm << " ";
    }
    cout << endl;
         
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