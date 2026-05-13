#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    using i128 = __int128_t;
    ull n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    auto dig = [&] (i128 x) {
        ll cnt = 0;
        while(x > 0) {
            x = x / 10;
            cnt++;
        }
        return cnt;
    };

    i128 curr = 1;
    for (ll i = 0; i < n; i++) {
        curr = curr * a[i];
        if(dig(curr) > k) curr = 1;
    }
    
    cout << (ll)curr << endl;
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