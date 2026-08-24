#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll a, b; cin >> a >> b;
    bool chk = false;
    if(a + b == 9) chk = true;
    if(a * b == 9) chk = true;
    if(a - b == 9) chk = true;
    if(9 * b == a) chk = true;

    if(chk) cout << "Nine" << endl;
    else cout << "Nein" << endl;
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