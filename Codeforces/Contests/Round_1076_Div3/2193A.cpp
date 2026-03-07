#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, s, x; cin >> n >> s >> x;
    vector<ll> a(n); inarr(a, n);
    ll sm = accumulate(all(a), 0LL);
    ll diff = s - sm;
    if(s < sm || (diff % x != 0)) {
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
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