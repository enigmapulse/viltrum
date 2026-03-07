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
    vector<ll> perm(n); set<ll> available;
    for (ll i = 2; i <= n; i++) available.insert(i); 
    perm[n - 1] = 1;
    for (ll i = 1; i < n - 1; i++) {
        perm[i] = 1 ^ (i + 1);
        available.erase(perm[i]);
    }
    
    perm[0] = *available.begin();
    if(n & 1){for(auto c : perm) cout << c << " ";
    cout << endl;}
    else {
        ll x = (n & -n);
        if(x >= n) cout << -1 << endl;
        else {
            swap(perm[0], perm[x - 1]);
            for(auto c : perm) cout << c << " ";
            cout << endl;
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