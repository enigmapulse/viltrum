#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<string> a(n); inarr(a, n);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(i == j) {
                if(a[i][j] == '1') continue;
                else {
                    cout << "No" << endl;
                    return;
                }
            }
            if (a[i][j] == '1' && a[j][i] == '1') {
                cout << "No" << endl;
                return;
            }  
        }
    }
    
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(a[i][j] == '1') {
                adj[i].push_back(j);
            }
        }
    }
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                if(a[j][k] == '1' && a[i][k] == '1') {
                    a[i][j] = '0';
                }
            }
        }
    }
    
    cout << "Yes" << endl;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(a[i][j] == '1') cout << i + 1 << " " << j + 1 << endl;
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