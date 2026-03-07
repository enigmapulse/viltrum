#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    vector<ll> a(4); cin >> a[0] >> a[1] >> a[2] >> a[3];

    bool chk = false;
    do {
        ll m1 = a[1] - a[0];
        ll m2 = a[3] - a[2];
        ll m3 = a[3] - a[1];
        ll m4 = a[2] - a[0];
        chk |= (m1 == m2 && m3 == m4);
    } while(next_permutation(all(a)));

    if(chk) cout << "YES" << endl;
    else cout << "NO" << endl;
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