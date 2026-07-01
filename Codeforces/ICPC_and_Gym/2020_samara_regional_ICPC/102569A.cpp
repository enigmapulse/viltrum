#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
        ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    for(ll i = 1; i <= n; i++) v[i] -= v[i - 1];
    ll q;
    cin >> q;
    while (q>0) {
        ll a, b, x;
        cin >> a >> b >> x;
        if((b-a) & 1) {
            if(a&1) v[n-1]+=x;
            else v[n-1]-=x;
        }
        cout << v[n-1] << endl;
        q--;
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