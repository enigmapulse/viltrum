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
    vector<ll> a(n); inarr(a, n);

    auto chk = [&] (ll x) {
        ll curr = x;
        ll con = 0;
        for (ll i = 0; i < n; i++) {
            if(a[i] <= con) {
                con++;
            }
            else if (curr) {
                con++; curr--;
            }
        }
        return (con >= m);
    };
    
    ll lo = 0, hi = m;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
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