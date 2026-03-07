#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n); inarr(a, n);
    map<ll, ll> mp; for(auto x : a) mp[x]++;

    for (ll i = 1; i < x; i++) {
        if(mp[i] % (i + 1) != 0) {
            cout << "No" << endl;
            return;
        }

        mp[i + 1] += (mp[i] / (i + 1));
    }
    
    cout << "Yes" << endl;
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