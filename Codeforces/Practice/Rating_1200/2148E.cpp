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
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp; for(auto x : a) mp[x]++;
    for(auto [val, cnt] : mp) {
        if(cnt % k) {
            cout << 0 << "\n";
            return;
        }
        else mp[val] = mp[val] / k;
    }

    map<ll, ll> curr; ll cnt = 0;
    ll l = 0, r = 0; curr[a[0]]++;
    while(l <= r) {
        while(r < n && curr[a[r]] <= mp[a[r]]) {
            r++; curr[a[r]]++;
        }
        cnt += (r - l);
        curr[a[l]]--; l++;
    }

    cout << cnt << endl;
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