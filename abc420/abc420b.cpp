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
    vector<string> s(n, string (m, ' ')); inarr(s, n);
    
    vector<ll> ans(n, 0);
    for (ll j = 0; j < m; j++) {
        ll cnt0 = 0, cnt1 = 0;
        for (ll i = 0; i < n; i++) {
            if(s[i][j] == '0') cnt0++;
            else cnt1++;
        }
        if(cnt0 == 0 || cnt1 == 0) {
            for (ll i = 0; i < n; i++)
            {
                ans[i]++;
            }
        }
        else if(cnt0 < cnt1) {
            for (ll i = 0; i < n; i++)
            {
                if(s[i][j] == '0')ans[i]++;
            }
        }
        else {
            for (ll i = 0; i < n; i++)
            {
                if(s[i][j] == '1') ans[i]++;
            }
        }
    }
    
    ll mx = *max_element(all(ans));
    for (ll i = 0; i < n; i++)
    {
        if(ans[i] == mx) cout << i + 1 << " ";
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