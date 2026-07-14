#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> prefix(1e6 + 1, 0);
    for (ll i = 0; i < n; i++) {
        ll idx; cin >> idx;
        cin >> prefix[idx];
    }
    
    vector<ll> basis = {1, 10, 100, 1000, 10000, 100000};
    // calculate the prefix sum over all directions
    for (int dir = 0; dir < 6; dir++) {
        for (ll mask = 1; mask <= 1e6; mask++) {
            if((mask / basis[dir]) % 10) prefix[mask] += prefix[mask - basis[dir]];
        }
    }
    
    ll q; cin >> q;
    while (q--) {
        string x, y; cin >> x >> y;
        ll ans = 0;

        bool valid = true;
        for (int i = 0; i < 6; i++) {
            if (x[i] > y[i]) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << 0 << endl;
            continue;
        }

        // 1 means upper, 0 means lower - 1
        for (ll mask = 0; mask < 64; mask++) {
            ll idx = 0; bool skip = false;
            ll cnt = __builtin_popcountll(mask);
            for (ll bit = 0; bit < 6; bit++) {
                if((mask >> bit) & 1) idx += (y[bit] - '0') * basis[5 - bit];
                else {
                    if(x[bit] == '0') {skip = true; break;}
                    idx += ((x[bit] - '0') - 1) * basis[5 - bit];
                }
            }
            if(skip) continue;
            if(cnt & 1) ans -= prefix[idx];
            else ans += prefix[idx];
        }
        cout << max(ans, 0ll) << endl;
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