#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, a1, k, p; cin >> n >> a1 >> k >> p;

    vector<ll> top;
    ll curr = a1;
    for (ll i = 0; i < n; i++) {
        if (top.size() < 5) {
            top.push_back(curr);
            sort(all(top));
        } else if (curr > top[0]) {
            top[0] = curr;
            sort(all(top));
        }

        curr = (curr * k) % p;
    }

    for (auto x : top) cout << x << " ";
    cout << endl;
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