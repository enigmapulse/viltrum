#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<ll> area(n, 0);
    for (ll i = 0; i < n - 1; i++) {
        area[i] = (x[i] * y[i + 1] - x[i + 1] * y[i]);
        if(i) area[i] += area[i - 1];
    }
    ll tot_area = area.back();
    
    vector<ll> cx(n, 0);
    for (ll i = 0; i < n; i++) {
        cx[i] = (x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i]) * (x[i] + x[(i + 1) % n]);
        if(i) cx[i] += cx[i - 1];
    }
    ll tot_cx = cx.back();
    
    vector<ll> cy(n, 0);
    for (ll i = 0; i < n; i++) {
        cy[i] = (x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i]) * (y[i] + y[(i + 1) % n]);
        if(i) cy[i] += cy[i - 1];
    }
    ll tot_cy = cy.back();
    
    while (q--) {
        ll u, v; cin >> u >> v;
        u--; v--;
        ll big = max(u, v), small = min(u, v);
        ll A = area[big - 1] - (small ? area[small - 1] : 0ll);
        ll X = cx[big - 1] - (small ? cx[small - 1] : 0ll);
        ll Y = cy[big - 1] - (small ? cy[small - 1] : 0ll);
        if(v > u) {
            A = tot_area - A;
            X = tot_cx - X;
            Y = tot_cy - Y;
        }
        ll c_A = (x[u] * y[v] - x[v] * y[u]);
        A += c_A;
        X += c_A * (x[u] + x[v]);
        Y += c_A * (y[u] + y[v]);

        cout << fixed << setprecision(10) << (double)X / (3.0 * A) << " " << (double)Y / (3.0 * A) << endl;
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