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
};

void solve() {
    ll n; cin >> n;
    vector<point> p(n); 
    for (ll i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    auto recur = [&] (vector<ll>& points, ll n) -> vector<ll> {
        ll sz = points.size();
        if(sz <= n) {
            return 
        }
    };
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