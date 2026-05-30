#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, d; cin >> n >> d;
    vector<ll> a(n + 1), b(n + 1); inarr(a, n); inarr(b, n);

    vector<ll> a_inv(n + 1), b_inv(n + 1);
    for (ll i = 1; i <= n; i++) {
        a_inv[a[i]] = i;
        b_inv[b[i]] = i;
    }
    
    ll curr = 0;
    vector<ll> c(n + 1);
    for (ll i = 1; i <= n; i++) {
        c[i] = a_inv[b[i]];
        if(i > 1) {
            curr += (c[i] < c[i - 1]);
        }
    }
    cout << c[n] - n + curr * n << endl;

    for (ll i = 1; i < d; i++) {
        ll op, x, y; cin >> op >> x >> y;
        if(op == 2) {
            swap(b_inv[b[x]], b_inv[b[y]]);
            swap(b[x], b[y]);
            set<ll> to_check = {x, y};
            if(x > 1) to_check.insert(x - 1);
            if(y > 1) to_check.insert(y - 1);

            ll p = 0;
            for(auto it : to_check) p += (c[it] > c[it + 1]);
            swap(c[x], c[y]);
            ll nw = 0;
            for(auto it : to_check) nw += (c[it] > c[it + 1]);
            curr += nw - p;
            cout << c[n] - n + curr * n << endl;
        }
        else {
            swap(a_inv[a[x]], a_inv[a[y]]);
            swap(a[x], a[y]);
            set<ll> to_check = {b_inv[a[x]], b_inv[a[y]]};
            if(b_inv[a[x]] > 1) to_check.insert(b_inv[a[x]] - 1);
            if(b_inv[a[y]] > 1) to_check.insert(b_inv[a[y]] - 1);

            ll p = 0;
            for(auto it : to_check) p += (c[it] > c[it + 1]);
            swap(c[b_inv[a[x]]], c[b_inv[a[y]]]);
            ll nx = 0;
            for(auto it : to_check) nx += (c[it] > c[it + 1]);
            curr += nx - p;
            cout << c[n] - n + curr * n << endl;
        }
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