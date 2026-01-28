#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (ll _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string r; cin >> r;
    ll n = r.length();
    ll ans = 0;

    if (r[0] == 'u') {
        r[0] = 's';
        ans++;
    }
    if (r[n - 1] == 'u') {
        r[n - 1] = 's';
        ans++;
    }

    for (ll i = 0; i < n - 1; i++) {
        if (r[i] == 'u' && r[i + 1] == 'u') {
            r[i + 1] = 's'; 
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}