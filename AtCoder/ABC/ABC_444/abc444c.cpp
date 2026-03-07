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
    vector<ll> a(n); inarr(a, n);

    ll sm = accumulate(all(a), 0LL);

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) mp[a[i]]++;

    ll mx = *max_element(all(a));
    
    vector<ll> ans;
    for (ll i = 1; i * i <= sm; i++) {
        if(sm % i != 0 || i < mx) continue;
        ll factor = sm / i;
        ll rem = n - mp[i];
        if(rem & 1) continue;
        if(rem / 2 != factor - mp[i]) continue;
        ans.push_back(i);
    }
    
    for (ll j = 1; j * j < sm; j++) {
        if(sm % j != 0) continue;
        ll i = sm / j;
        if(sm % i != 0 || i < mx) continue;
        ll factor = sm / i;
        ll rem = n - mp[i];
        if(rem & 1) continue;
        if(rem / 2 != factor - mp[i]) continue;
        ans.push_back(i);
    }

    sort(all(ans));
    for(auto x : ans) cout << x << " ";
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