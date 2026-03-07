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
    vector<string> a(n); inarr(a, n);
    ll mx = 0;
    for(auto str : a) mx = max(mx, (ll)str.size());
    for(auto str : a) {
        ll rem = mx - str.size();
        for (ll i = 0; i < rem / 2; i++) cout << ".";
        cout << str;
        for (ll i = 0; i < rem / 2; i++) cout << ".";
        cout << endl;
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