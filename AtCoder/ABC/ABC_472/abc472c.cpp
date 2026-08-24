#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n); inarr(a, n);

    vector<ll> pre(n, 0); 
    for (ll i = 0; i < n; i++) {
        pre[i] = a[i] + (i ? pre[i - 1] : 0ll);
        if(pre[i] - (i < m ? 0ll : pre[i - m]) <= k) {
            cout << "Yes" << endl;
        }
        else {
            pre[i] = (i ? pre[i - 1] : 0ll);
            cout << "No" << endl;
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