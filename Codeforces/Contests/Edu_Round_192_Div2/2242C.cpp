#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); inarr(a, n);

    vector<ll> cnt;
    ll idx = 0;
    while(idx < n) {
        ll start = idx;
        while(idx != n - 1 && a[idx] == a[idx + 1]) idx++;
        cnt.push_back(idx - start + 1);
        idx++;
    }
    sort(all(cnt));
    
    ll ans = 0, sm = 0, c = cnt.size();
    for (ll i = 1; i <= c; ++i) {
        sm += cnt[c - i];
        if (i < c && cnt[c - i - 1] == cnt[c - i]) {
            continue;
        }
        if ((m - sm) % i == 0) {
            ll x = (m - sm) / i; 
            if (x >= 1 - cnt[c - i]) {
                ans++;
            }
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