#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (ll _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vector<ll> p(n); inarr(p, n);

    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') { 
            b[i] = (p[i] - 1) / 2;
            a[i] = p[i] - b[i];
        } else { 
            a[i] = (p[i] - 1) / 2;
            b[i] = p[i] - a[i];
        }

        x -= a[i];
        y -= b[i];
        if(x < 0 || y < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    
    ll par_none = abs(x - y);
    if(par_none == 0) {
        cout << "YES" << endl;
        return;
    }

    if(x > y) {
        for(auto ch : s) {
            if(ch == '0') {
                cout << "YES" << endl;
                return;
            }
        }
        ll sl = 0;
        for(ll i=0; i<n; i++) sl += (b[i] - a[i] - 1);
        
        if (x - y <= sl) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else { 
        for(auto ch : s) {
            if(ch == '1') {
                cout << "YES" << endl;
                return;
            }
        }
        ll sl = 0;
        for(ll i=0; i<n; i++) sl += (a[i] - b[i] - 1);
        
        if (y - x <= sl) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}