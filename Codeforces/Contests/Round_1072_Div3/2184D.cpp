#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

vector<vector<ll>> C(65, vector<ll> (65));

void solve() {
    ll n, k; cin >> n >> k;
    if(k > 60) {
        cout << 0 << endl;
        return;
    }

    ll d = 0; ll tmp = n;
    while(tmp) {tmp /= 2; d++;}

    ll ans = 0;
    for (ll i = 1; i < d; i++) {
        ll cnt = k - i; 
        if(cnt < 0) continue;
        for (ll j = 0; j <= min(i - 1, cnt); j++) {
            ans += C[i - 1][j];
        }
    }
    
    if(d <= k) ans++;
    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (ll i = 0; i <= 64; i++) {
        C[i][0] = 1;
        for (ll j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}