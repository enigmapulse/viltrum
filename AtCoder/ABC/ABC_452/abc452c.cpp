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
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    
    ll m; cin >> m;
    vector<string> s;
    bool chk[11][11][26] = {};
    for (ll i = 0; i < m; i++) {
        string x; cin >> x;
        s.push_back(x);
        for(ll j = 0; j < x.size(); ++j) {
            chk[x.size()][j + 1][x[j] - 'a'] = true;
        }
    }
    
    for (ll i = 0; i < m; i++) {
        string target = s[i];
        if(target.size() != n) {
            cout << "No" << endl;
            continue;
        }
        bool ok = true;
        for (ll j = 0; j < n; ++j) {
            ok &= chk[a[j]][b[j]][target[j] - 'a'];
        }
        if(ok) cout << "Yes" << endl;
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