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
    vector<vector<ll>> pre(n, vector<ll> (m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            char ch; cin >> ch;
            pre[i][j] = ch - '0';
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j < m; j++) pre[i][j] += pre[i][j - 1];
        if(i) for (ll j = 0; j < m; j++) pre[i][j] += pre[i - 1][j];
    }

    ll cnt = 0;
    for (ll row1 = 0; row1 < n; row1++) {
        for (ll row2 = row1; row2 < n; row2++) {
            vector<ll> sm(m, 0);
            for (ll j = 0; j < m; j++) sm[j] = pre[row2][j] - (row1 > 0 ? pre[row1 - 1][j] : 0ll);
            map<ll, ll> f; f[0] = 1;
            for (ll i = 0; i < m; i++) {
                if(f.contains(sm[i] - k)) cnt += f[sm[i] - k];
                f[sm[i]]++;
            }
        }
    }
    cout << cnt << endl;
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