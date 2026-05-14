#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll x, y, z; cin >> x >> y >> z;

    if(x == 0 && y == 0 && z == 0) {
        cout << 0 << endl;
        return;
    }

    ll totx = 0, toty = 0, totz = 0;
    for(auto ch : s) {
        if(ch == 'N') toty++;
        if(ch == 'S') toty--;
        if(ch == 'U') totz++;
        if(ch == 'D') totz--;
        if(ch == 'E') totx++;
        if(ch == 'W') totx--;
    }

    auto chk = [&] (ll t, ll cx, ll cy, ll cz, ll ct) {
        ll contrx = abs(t * totx + cx - x);
        ll contry = abs(t * toty + cy - y);
        ll contrz = abs(t * totz + cz - z);
        ll steps = abs(t * n + ct);
        return ((contrx + contry + contrz) <= steps);
    };

    ll ans = 2e18;
    ll currx = 0, curry = 0, currz = 0, cnt = 0;
    for(auto ch : s) {
        if(ch == 'N') curry++;
        if(ch == 'S') curry--;
        if(ch == 'U') currz++;
        if(ch == 'D') currz--;
        if(ch == 'E') currx++;
        if(ch == 'W') currx--;
        cnt++;

        ll lo = 0, hi = 4e9;
        while(lo < hi) {
            ll mid = lo + (hi - lo)/2;
            if(chk(mid, currx, curry, currz, cnt)) hi = mid;
            else lo = mid + 1;
        }
        if(chk(lo, currx, curry, currz, cnt)) {
            ans = min(lo * n + cnt, ans);
        }
    }

    if(ans == 2e18) cout << -1 << endl;
    else cout << ans << endl;
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