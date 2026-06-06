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
    ll n, m; cin >> n >> m;
    ll dist1, dist2, dist3;
    dist1 = dist2 = dist3 = 0;
    cout << "? " << 1 << " " << 1 << endl << flush;
    cin >> dist1;
    cout << "? " << 1 << " " << m << endl << flush;
    cin >> dist2;
    cout << "? " << n << " " << m << endl << flush;
    cin >> dist3;

    struct pt {ll x, y;};
    pt pt1 = {1 + dist1, 1 + dist1};
    pt pt2 = {1 + dist2, m - dist2};
    pt pt3 = {n - dist3, m - dist3};
    
    auto f = [](ll a, ll b, ll c) {
        return (a == b || a == c) ? a : b;
    };

    ll x = f(pt1.x, pt2.x, pt3.x);
    ll y = f(pt1.y, pt2.y, pt3.y);

    cout << "! " << x << " " << y << endl << flush;
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