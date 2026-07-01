#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll> (k));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < k; j++) cin >> a[i][j];
    }
    
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++) {
        bool flag = false;
        for (ll j = 0; j < k; j++) {
            if(a[i][j] > 0 && a[i + 1][j] > 0) flag = true;
        }
        if(flag) cnt++;
    }
    if(cnt & 1) cout <<"Alice" << endl;
    else cout << "Bob" << endl;
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