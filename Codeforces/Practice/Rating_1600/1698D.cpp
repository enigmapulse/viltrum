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

    auto chk = [&] (vector<ll>& x) {
        ll cnt = 0;
        for (ll i = 1; i <= x.size(); i++) cnt += (x[i - 1] <= x.size());
        return (cnt & 1);
    };

    ll lo = 1, hi = n;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        
        vector<ll> inp(mid);
        cout << "? " << 1 << " " << mid << endl << flush;
        for (ll i = 0; i < mid; i++) cin >> inp[i];
        
        if(chk(inp)) hi = mid;
        else lo = mid + 1;
    }

    cout << "! " << lo << endl << flush;
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