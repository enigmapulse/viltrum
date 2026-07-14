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
    vector<ll> a(n); inarr(a, n);
    vector<ll> mx(n, 0); 
    vector<ll> wait(n, 0);
    for (ll i = 0; i < n; i++) {
        mx[i] = (i == 0) ? a[i] : max(mx[i - 1], a[i]);
        wait[i] = mx[i] - a[i];
    }
    ll tot = accumulate(all(wait), 0ll) ;
    for (ll i = 0; i < n; i++) {
        if(i == 0 || a[i] > mx[i - 1]) {
            ll curr = (i == 0) ? 1 : mx[i - 1]; ll adv = 0;
            for (ll j = i + 1; j < n; j++) {
                curr = max(curr, a[j]);
                if(curr == mx[j]) break;
                adv += mx[j] - curr;
            }
            wait[i] = adv;
        }
    }
    ll ans = tot - *max_element(all(wait));
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