#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    ll vol = 0, play = 0;
    while(n--) {
        ll op; cin >> op;
        if(op == 1) vol++;
        else if(op == 2) vol = max(vol - 1, 0LL);
        else play = (play ^ 1);
        if(vol >= 3 && play) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
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