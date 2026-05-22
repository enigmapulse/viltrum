#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define f first
#define s second

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);

    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) mp[a[i]]++;
    
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(b[i] == a[i] && mp[b[i]] <= 1) cnt++;
        else if(b[i] != a[i] && mp[b[i]] == 0) cnt++;
        else mp[b[i]]--;
    }
    cout << n - 1 - cnt - (cnt & 1) << endl;
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