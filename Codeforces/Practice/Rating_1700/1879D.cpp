#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define BITS 32
const ll MOD = 998244353;

using namespace std;
bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> bits_pref(n), bits_suff(n);
    vector<ll> bits_pref_sm(n), bits_suff_sm(n);
    ll ans = 0;

    for (ll j = 0; j < BITS; j++) {
        for (ll i = 0; i < n; i++) {
                bits_pref[i] = (a[i] >> j) & 1;
                bits_suff[i] = bits_pref[i];
                if(i != 0) bits_pref[i] = (bits_pref[i] + bits_pref[i-1]) % 2;
        }
        for (ll i = 0; i < n; i++) {
                if(i != 0) bits_pref_sm[i] = (bits_pref[i] + bits_pref_sm[i-1]);
                else bits_pref_sm[0] = bits_pref[0];
        }
        for (ll i = n - 1; i >= 0; i--) {
                if(i != n-1) bits_suff[i] = (bits_suff[i] + bits_suff[i+1]) % 2;
        }
        for (ll i = n - 1; i >= 0; i--) {
                if(i != n-1) bits_suff_sm[i] = (bits_suff[i] + bits_suff_sm[i+1]);
                else bits_suff_sm[n - 1] = bits_suff[n - 1];
        }
        
        for (ll r = 0; r < n; r++) {
            ll shift = (1LL << j); shift %= MOD;
            ll cnt = 0;
            if((r < n - 1 ? bits_suff[r + 1] : 0ll) & 1) cnt += r + 1 - bits_suff_sm[0] + (r < n - 1 ? bits_suff_sm[r + 1] : 0ll);
            else cnt += bits_suff_sm[0] - (r < n - 1 ? bits_suff_sm[r + 1] : 0ll);
            ans += ((cnt * shift) % MOD * (r + 2)) % MOD;
        }
        for (ll l = 0; l < n; l++) {
            ll shift = (1LL << j); shift %= MOD;
            ll cnt = 0;
            if((l != 0 ? bits_pref[l - 1] : 0ll) & 1) cnt += n - l - bits_pref_sm[n - 1] + (l != 0 ? bits_pref_sm[l - 1] : 0ll);
            else cnt += bits_pref_sm[n - 1] - (l != 0 ? bits_pref_sm[l - 1] : 0ll);
            ans = (ans - ((cnt * shift) % MOD * (l + 1)) % MOD + MOD) % MOD;
        }
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