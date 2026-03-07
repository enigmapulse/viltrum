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
    vector<ll> a(n); inarr(a, n);
    vector<ll> b(n); inarr(b, n);
    vector<ll> c(n); inarr(c, n);

    ll cnt1 = 0;
    for (ll i = 0; i < n; i++) {
        bool val = true;
        for (ll j = 0; j < n; j++) {
            if(b[(i + j) % n] <= a[j]) val = false;
        }
        if(val) cnt1++;
    }
    
    ll cnt2 = 0;
    for (ll i = 0; i < n; i++) {
        bool val = true;
        for (ll j = 0; j < n; j++) {
            if(c[(i + j) % n] <= b[j]) val = false;
        }
        if(val) cnt2++;
    }

    cout << n * cnt1 * cnt2 << endl;
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