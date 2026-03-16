#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll l, r, d, u; cin >> l >> r >> d >> u;

    ll ans = 0;
    for (ll i = 0; i <= 1e6; i += 2) {

        if (i == 0) {
            if (l <= 0 && 0 <= r && d <= 0 && 0 <= u) ans++;
            continue;
        }

        // upper line 
        if(d <= i && u >= i) ans += max(0LL, min(i, r) - max(-i, l) + 1);
        // below line 
        if(d <= -i && u >= -i) ans += max(0LL, min(i, r) - max(-i, l) + 1);
        // right line 
        if(l <= i && r >= i) ans += max(0LL, min(i, u) - max(-i, d) + 1);
        // left line 
        if(l <= -i && r >= -i) ans += max(0LL, min(i, u) - max(-i, d) + 1);

        // remove overcounting
        if(l <= i && i <= r && d <= i && i <= u) ans--;
        if(l <= i && i <= r && d <= -i && -i <= u) ans--;
        if(l <= -i && -i <= r && d <= i && i <= u) ans--;
        if(l <= -i && -i <= r && d <= -i && -i <= u) ans--;
    }
    
    cout << ans << endl;
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