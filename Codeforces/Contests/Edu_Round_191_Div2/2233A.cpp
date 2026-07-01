#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x, y, z; cin >> n >> x >> y >> z;
    ll choice1 = (n + x + y - 1) / (x + y);
    ll choice2 = (n + x - 1) / x;
    if(choice2 > z) {
        ll lines = x * z;
        ll rem = n - lines;
        choice2 = z + (rem + x + 10 * y - 1) / (x + 10 * y);
    }
    cout << min(choice1, choice2) << endl;
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