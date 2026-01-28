#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {

   ll n, k; cin >> n >> k;
   string s; cin >> s;
   vector<ll> l(k), r(k);
   inarr(l, k); inarr(r, k);

   string t(n, ' ');
   for(ll i = 0; i < k; i++) {
        for (ll idx = l[i]; idx <= r[i]; idx++) {
            t[idx - 1] = s[l[i] + r[i] - idx - 1];
        }
   }

   ll q; cin >> q;
   vector<ll> flip(n + 1, 0);
   while(q--) {
        ll x; cin >> x;

        auto idx = upper_bound(all(l), x) - l.begin() - 1;
        ll start = min(l[idx] + r[idx] - x, x);
        ll end = max(l[idx] + r[idx] - x, x);
        flip[start - 1] ^= 1; flip[end] ^= 1;
   }

   for (ll i = 1; i <= n; i++) flip[i] ^= flip[i - 1];
   
   for (ll i = 0; i < n; i++) {
        if(flip[i]) cout << t[i];
        else cout << s[i];
   }
   cout << endl;
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