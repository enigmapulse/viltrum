#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    vector<ll> sides = {a, b, c, d};
    sort(all(sides));

    auto chk = [&] () {
        bool chk1 = ((sides[1] - sides[0]) == (sides[3] - sides[2]));
        bool chk2 = ((sides[2] - sides[0]) == (sides[3] - sides[1]));
        return (chk1 & chk2);
    };

    do {
        if(chk()) {
            cout << "YES" << endl;
            return;
        }
    } while(next_permutation(all(sides)));
    cout << "NO" << endl;
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