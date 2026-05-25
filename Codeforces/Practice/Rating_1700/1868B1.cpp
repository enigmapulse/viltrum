#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll nxt(ll x) {
    if (x <= 1) return 1ll;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll sm = accumulate(all(a), 0ll);
    ll val = sm / n;
    if(val * n != sm) {
        cout << "No" << endl;
        return;
    }

    vector<ll> net(32, 0);
    for (ll i = 0; i < n; i++) {
        if(a[i] < val) {

        }
        else if(a[i] > val) {

        }
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