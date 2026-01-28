#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

struct point {
    ll x, y;

    point(ll a = 0, ll b = 0) {
        x = a;
        y = b;
    }
};

ll cross(point& a, point& b) {
    return a.x * b.y - a.y * b.x;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<point> p(n);
    for (ll i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    auto cmp = [&] (point& a, point& b) {
        ll c = cross(a, b);
        if(c = 0) return (b.x > a.x);
        else return (c > 0);
    };
    sort(all(p), cmp);

    while(q--) {
        ll a, b; cin >> a >> b;
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