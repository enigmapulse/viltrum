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
    ll lo = 1; ll hi = n;
    ll ans = 0;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;

        ll left = 0, right = 0;
        cout << "? " << lo << " " << mid << endl << flush;
        cin >> left;

        cout << "? " << mid + 1 << " " << hi << endl << flush;
        cin >> right;

        if(left > right) hi = mid;
        else lo = mid + 1;
    }

    cout << "? " << lo << " " << lo << endl << flush;
    cin >> ans;

    cout << "! " << ans << endl << flush;
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