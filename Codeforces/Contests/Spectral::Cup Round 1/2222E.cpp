#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll findC(ll n) {
    ll lo = 1, hi = (1LL << n) - 1;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        cout << "Q " << mid << endl << flush;
        ll res; cin >> res;
        if(res == 1) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

void solve() {
    ll n; cin >> n;

    // init element in set S
    cout << 0 << endl << flush;

    cout << "I 0" << endl << flush;
    ll sz; cin >> sz;

    if(sz == 2) {
        // ops was xor / or and S = {0, c}
        ll c = findC(n);
        ll ck = (c & (c - 1));
        if(ck != 0) {
            cout << "I " << ck << endl << flush;
            ll sz; cin >> sz;
            if(sz == 2) cout << "A 2 " << c << endl << flush;
            else cout << "A 3 " << c << endl << flush; 
        }
        else {
            ll z = (c == 1) ? 2 : 1;
            ll x = c | z;
            cout << "I " << x << endl << flush;
            ll y; cin >> y; 
            
            cout << "Q " << x << endl << flush;
            ll cnt; cin >> cnt;
            if (cnt >= 1) cout << "A 2 " << c << endl << flush;
            else cout << "A 3 " << c << endl << flush;
        }
    }
    else {
        // ops was and
        cout << "I " << (1LL << n) - 1 << endl << flush;
        ll x; cin >> x;
        // S = {0, c}
        ll c = findC(n);
        cout << "A 1 " << c << endl << flush;
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