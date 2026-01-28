#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

void solve() {
    /*
    if we start doing it from bwd then here is the thing about it, s[n] = 1
    if s[n - 1] = 0 then we know we have to put it in between 
    it is easier to deal with 1s starting from the beginning and with 0s
    starting from the end 
    */
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