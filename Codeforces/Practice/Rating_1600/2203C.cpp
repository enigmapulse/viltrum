#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll s, m; cin >> s >> m;

    ll factor = (m & -m);
    if(s % factor != 0) {
        cout << -1 << endl;
        return;
    }
    
    m = m / factor; s = s / factor;
    ll lo = 1, hi = s;
    vector<ll> cnt(61, -1);
    for (ll i = 60; i >= 0; i--) {
        if((m >> i) & 1) {
            cnt[i] = (s / (1ll << i));
            s = (s % (1ll << i));
        }
    }

    auto chk = [&] (ll x) {
        vector<ll> cur = cnt;
        ll idx = 60;
        while(idx >= 0) {
            if(cur[idx] > x) {
                ll excess = cur[idx] - x;
                cur[idx] = x;
                ll nxt = idx - 1; excess *= 2;
                while(nxt >= 0 && cur[nxt] == -1) {
                    nxt--;
                    excess *= 2;
                }
                if(nxt == -1) return false;
                cur[nxt] += excess;
                idx = nxt;
            }
            else idx--;
        }
        return true;
    };
    
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
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