#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> ways(10, 0);
    for (ll i = 0; i < 10; i++) {
        for (ll j = 0; j < 10; j++) {
            for (ll k = 0; k < 10; k++) {
                ll sm = i + j + k;
                if(sm < 10) ways[sm]++;
            }
        }
    }
    
    ll ans = 1;
    while(n) {
        ll d = n % 10;
        ans = ans * ways[d];
        n /= 10;
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