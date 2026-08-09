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

    auto chk = [&] (ll x) {
        return (x * (x + 1) <= 2 * (n + m));
    };

    ll lo = 1, hi = (n + m + 5);
    while(lo < hi) {
        ll mid = lo  + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }

    ll steps = lo;
    lo = (lo * (lo + 1)) / 2;
    ll bestx = (n - m + lo)/2;
    ll besty = lo - bestx;

    if(n < bestx) {
        bestx = n;
        besty = lo - bestx;
    }
    if(m < besty) {
        besty = m;
        bestx = lo - besty;
    }
    if(0 > bestx) {
        bestx = 0;
        besty = lo - bestx;
    }
    if(0 > besty) {
        besty = 0;
        bestx = lo - besty;
    }

    string path = "";
    for (ll i = 1; i <= steps; i++) {
        ll wt = steps - i + 1;
        if (bestx >= wt) {
            path += 'X';
            bestx -= wt;
        } else {
            path += 'Y';
            besty -= wt;
        }
    }
    
    cout << path << endl;
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