#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;
    vector<ll> a(x), b(y); 
    inarr(a, x); inarr(b, y);

    ll lim = n + m - 1;
    ll ta = 0, tb = 0;

    map<ll, ll> mp;
    for(auto x : a) mp[x]++;
    for(auto x : b) mp[x]+=2;
    
    ll ans = 0;
    for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
        ll type = it -> second, val = it -> first;
        if(lim == 0) break;
        if(type == 1) {
            if(ta < n) {
                ta++; ans += val;
                lim--;
            }
        }
        else if(type == 2) {
            if(tb < m) {
                tb++; ans += val;
                lim--;
            }
        }
        else {
            ans += val; lim--;
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