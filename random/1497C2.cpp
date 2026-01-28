#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define outarr(a, n) for (int _i = 0; _i < (n); _i++) cout << (a)[_i] << " \n"[_i == n - 1];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> ans(k, 1);
    n -= (k - 3);
    if(n & 1) cout << (n - 1)/2 << " "<< (n - 1)/2 << " " << 1 << " ";
    else {
        if(n % 4 == 0) cout << n / 2 << " " << n / 4 << " " << n / 4 << " ";
        else cout << n/2 - 1 << " " << n / 2 -  1 << " " << 2 << " ";
    }
    for (ll i = 0; i < k - 3; i++) cout << 1 << " ";
    cout << endl;\
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