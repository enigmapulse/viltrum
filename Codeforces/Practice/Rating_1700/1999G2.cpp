#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll lo = 1, hi = 1000;
    while(lo < hi) {
        ll ot = lo + (hi - lo)/3, tt = hi - (hi - lo)/3;
        cout << "? " << ot << " " << tt << endl << flush;
        ll ans; cin >> ans;
        if(ans == ot * tt) lo = tt + 1;
        else if(ans == (ot + 1) * (tt + 1)) hi = ot;
        else {
            lo = ot + 1;
            hi = tt;
        }
    }

    cout << "! " << lo << endl;
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