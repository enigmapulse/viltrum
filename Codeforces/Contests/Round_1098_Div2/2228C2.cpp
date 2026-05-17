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
    vector<ll> dig(n); inarr(dig, n);
    ll x, y; x = dig[0], y = dig[n - 1];

    string b = to_string(a);
    ll len = b.size();
    ull ans = ULLONG_MAX;
    ull ua = a;

    for (ll i = 0; i <= len; i++) {
        bool chk = true;
        ull pref = 0;
        
        for (ll j = 0; j < i; j++) {
            ll v = b[j] - '0';
            bool val = false;
            for (int d : dig) if (v == d) val = true;
            if (!val) chk = false;
            pref = pref * 10 + v;
        }
        
        if (!chk) continue; 
        ll cnt = len - i; 

        if (cnt == 0) {
            ans = min(ans, ab(pref, ua));
            continue;
        }

        ull m = 1;
        for (ll j = 0; j < cnt; j++) {
            m *= 10;
        }

        if (i == 0) {
            ull px = x;
            if(px == 0 && n > 1) px = dig[1];
            for (ll j = 0; j < len; j++) {
                px = px * 10 + x;
            }
            ans = min(ans, ab(px, ua));

            if(len > 1) {
                ull ql = 0;
                for (ll j = 0; j < len - 1; j++) {
                    ql = ql * 10 + y;
                }
                ans = min(ans, ab(ql, ua));
            }
        }
        ll v = b[i] - '0';
        for(auto d : dig) {
            if(d == v) continue;
            ull suf = d;
            ull rest = (d < v) ? y : x;
            for(int j = 1; j < cnt; j++) {
                suf = suf * 10 + rest;
            }
            ull r = pref * m + suf;
            ans = min(ans, ab(r, ua));
        } 
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