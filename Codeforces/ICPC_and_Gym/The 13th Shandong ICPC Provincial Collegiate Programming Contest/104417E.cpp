#include <bits/stdc++.h>
#define ll long long
#define i128 __int128
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k, m, a, b; cin >> n >> k >> m >> a >> b;

    if(k == 1) {
        if(n % m == 0) cout << 0 << endl;
        else cout << -1 << endl;
        return;
    }

    auto f = [&] (ll node) {
        ll cnt = 0;
        i128 l = node, r = node;
        while(true) {
            i128 q1 = (l + m - 1) / m;
            i128 q2 = r / m;
            if (q2 >= q1) break;
            l = (k * l);
            r = (k * r + k - 1);
            cnt++;
        }
        return cnt;
    };

    ll curr = n, ans = LLONG_MAX; 
    for (ll down = 0; down < 62; down++) {
        ans = min(ans, down * b + a * f(curr));
        if (curr == 0) break;
        curr = curr / k;
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