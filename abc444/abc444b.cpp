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

    auto digsum = [&] (ll num) {
        ll sm = 0;
        while(num) {
            sm += num % 10;
            num = num / 10;
        }
        return sm;
    };

    ll ct = 0;
    for (ll i = 1; i <= n; i++) {
        ct += (digsum(i) == k);
    }
    
    cout << ct << endl;
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