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
    vector<ll> a(n), b(n);
    inarr(a, n); inarr(b, n);

    ll cnt = 0, sm = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] != b[i]) {sm += a[i]; cnt++;}
    }
    if(cnt == 0) cout << 0 << endl;
    else if(sm & 1) cout << 1 << endl;
    else {
        if(sm == 0) {
            bool chk1 = false, chk2 = false;
            for (ll i = 0; i < n; i++) {
                if(a[i] + b[i] == 0) chk1 = true;
                if(a[i] + b[i] == 2) chk2 = true;
            }
            if(chk1 && chk2) cout << 2 << endl;
            else cout << -1 << endl;
        }
        else cout << 2 << endl;
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