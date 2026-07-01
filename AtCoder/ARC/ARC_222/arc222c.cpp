#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e16;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) inarr(a[i], n);
    
    vector<ll> odd(n, 0), even(n, 0);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if((i + j) & 1) odd[j] += a[i][j];
            else even[j] += a[i][j];
        }
    }

    auto f = [&] (ll i, ll j) {
        if(i >= 0 && i < n) {
            if((i + j) & 1) return odd[j];
            else return even[j];
        }
        else return INF;
    };
    
    vector<vector<ll>> ans(n, vector<ll> (n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll choice1 = f(i, j);
            ll choice2 = a[i][j] + f()
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