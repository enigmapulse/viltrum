#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll q; cin >> q;
    stack<ll> s;
    for (ll i = 0; i < 100; i++) {
        s.push(0);
    }
    
    while(q--) {
        ll ops; cin >> ops;
        if(ops == 1) {
            ll x; cin >> x;
            s.push(x);
        }
        else {
            cout << s.top() << endl;
            s.pop();
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