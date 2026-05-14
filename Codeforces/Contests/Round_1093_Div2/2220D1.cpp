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

    auto chk = [&] (ll idx) {
        cout << "? ";
        for (ll i = 1; i <= idx; i++) {
            cout << i << " ";
        }
        cout << endl << flush;
        ll cnt1; cin >> cnt1;
        
        cout << "? ";
        for (ll i = idx + 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl << flush;
        ll cnt2; cin >> cnt2;

        return (abs(cnt1 - cnt2) == 1);
    };

    ll lo = 1, hi = n;
    while(lo < hi) {
        ll left = lo + (hi - lo)/3;
        ll right = lo + 2 * (hi - lo)/3;
        
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