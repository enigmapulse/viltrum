#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a((1 << n)); inarr(a, (1 << n));

    vector<ll> x((1 << n), 0); x[0] = a[0];
    for (ll i = 1; i < (1 << n); i++) x[i] = a[i] ^ x[i - 1];
    
    while(q--) {
        ll b, c; cin >> b >> c;
        b = b - 1;
        ll idx = 0; ll cnt = 0;
        
        while(idx < n) {
            ll l = ((b >> idx) << idx);
            ll r = l; r += (1 << idx);
            r--; 

            ll our_stack = x[r] ^ (l > 0 ? x[l - 1] : 0) ^ c ^ a[b];

            r = r ^ (1 << idx); l = l ^ (1 << idx);
            ll opp_stack = x[r] ^ (l > 0 ? x[l - 1] : 0);

            if(opp_stack > our_stack) cnt += (1 << idx);
            else if(opp_stack == our_stack) {
                if((b >> idx) & 1) cnt += (1 << idx);
            }

            idx++;
        }
        cout << cnt << endl;
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