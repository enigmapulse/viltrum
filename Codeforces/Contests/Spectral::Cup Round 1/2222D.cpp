#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

vector<ll> compress(vector<ll>& a) {
    ll n = a.size();
    vector<pair<ll,ll>> v;

    for (ll i = 0; i < n; i++) {
        v.push_back({-a[i], i});
    }
    sort(all(v));

    vector<ll> na(n);
    for (ll rank = 0; rank < n; rank++) {
        ll oidx = v[rank].second;
        na[oidx] = rank + 1;
    }
    return na;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1, 0); inarr(a, n);
    for (ll i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    a.pop_back();
    
    vector na = compress(a);
    for(auto x : na) cout << x << " ";
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