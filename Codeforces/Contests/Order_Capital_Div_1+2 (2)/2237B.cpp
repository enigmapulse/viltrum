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

    vector<ll> c = a; sort(all(c));
    for (ll i = 0; i < n; i++) {
        if(c[i] > b[i]) {
            cout << -1 << endl;
            return;
        }
    }
    
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            ll f = -1;
            for (ll j = i + 1; j < n; j++) {
                if(a[j] <= b[i]) {
                    f = j;
                    cnt += j - i;
                    break;
                }
            }
            for (ll j = f; j > i; j--) {
                swap(a[j], a[j - 1]);
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