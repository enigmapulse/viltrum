#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll x, y; cin >> x >> y;

    ll p = x, q = y;
    p = (~y & x);
    ll cost = abs(p - x) + abs(q - y);

    {
        ll np = x, nq = (~x & y);
        ll c = abs(np - x) + abs(nq - y);
        if(c < cost) {
            p = np; q = nq; cost = c;
        }
    }

    {
        ll np = x, nq = y;
        for (ll i = 0; i < 32; i++) {
            if(((x >> i) & 1)) continue;
            np = (x & ~((1LL << (i)) - 1LL)) | (1LL << i);
            nq = y & (~np);
            ll c = abs(np - x) + abs(nq - y);
            if(c < cost) {
                p = np; q = nq; cost = c;
            }
        }
    }

    {
        ll np = x, nq = y;
        for (ll i = 0; i < 32; i++) {
            if(((y >> i) & 1)) continue;
            nq = (y & ~((1LL << (i)) - 1LL)) | (1LL << i);
            np = x & (~nq);
            ll c = abs(np - x) + abs(nq - y);
            if(c < cost) {
                q = nq; p = np; cost = c;
            }
        }
    }

    cout << p << " " << q << endl;
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