#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    vector<string> a(n); inarr(a, n);

    string ans = string(m, '0');
    ll idx = 0, tot = n;
    vector<bool> vis(n, false);
    while(idx < m) {
        ll cnt1 = 0;
        for (ll i = 0; i < n; i++) if(!vis[i]) cnt1 += (a[i][idx] == '1');
        ll cnt0 = tot - cnt1;
        if(cnt1 >= cnt0) {
            ans[idx] = '1';
            tot -= cnt1;
            for (ll i = 0; i < n; i++) {
                if(a[i][idx] == '1') vis[i] = true;
            }
        }
        else {
            tot -= cnt0;
            for (ll i = 0; i < n; i++) {
                if(a[i][idx] == '0') vis[i] = true;
            }
        }
        idx++;
    }
    
    if(tot != 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << ans << endl;
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