#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define ab(A, B) ((A) > (B) ? (A) - (B) : (B) - (A))

using namespace std;

bool mtipleTests = true;

void solve() {
    ll a, n; cin >> a >> n;
    ll x, y; cin >> x >> y;

    string b = to_string(a);
    ll len = b.size();
    ull ans = ULLONG_MAX;
    ull ua = a;

    for (ll i = 0; i <= len; i++) {
        bool chk = true;
        ull pref = 0;
        
        for (ll j = 0; j < i; j++) {
            ll v = b[j] - '0';
            if (v != x && v != y) chk = false;
            pref = pref * 10 + v;
        }
        
        if (!chk) continue; 
        ll cnt = len - i; 

        if (cnt == 0) {
            ans = min(ans, ab(pref, ua));
            continue;
        }

        ull p = 0, q = 0, r = 0, s = 0;
        ull m = 1;
        for (ll j = 0; j < cnt; j++) {
            p = 10 * p + x;
            if(j) r = 10 * r + x;
            else r = y;
            q = 10 * q + y;
            if(j) s = 10 * s + y;
            else s = x;
            m *= 10;
        }
        ull u = p, v = q;

        if (i == 0) {
            ull px = 10 * p + x;
            if(x == 0) px = 10 * r + x;
            ull ql = q / 10;
            
            ans = min(ans, ab(px, ua));
            if (len > 1) ans = min(ans, ab(ql, ua));
            else if (x == 0) ans = min(ans, ua);
        }
        r = pref * m + r;
        s = pref * m + s;
        u = pref * m + u;
        v = pref * m + v;
    
        ans = min({ans, ab(r, ua), ab(s, ua), ab(u, ua), ab(v, ua)});
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (mtipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}