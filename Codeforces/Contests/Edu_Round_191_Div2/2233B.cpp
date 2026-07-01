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
    vector<ll> a = {2, 1, 1, 2, 1, 2, 2, 1};
    vector<ll> b = {1,1,2,1,2,3,1,3,2,2,3,3};
    ll shift = 0;
    if(n % 2 == 0) {
        for (ll i = 0; i < n / 2; i++) {
        for(auto x : a) cout << x + shift << " ";
        shift += 2;
    }
    }
    else {
        for (ll i = 0; i < (n - 3) / 2; i++) {
            for(auto x : a) cout << x + shift << " ";
            shift += 2;
        }
            for(auto x : b) cout << x + shift << " ";
    }
    cout << endl;
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