#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> perm(n); iota(all(perm), 1);

    ll mx = 1e12;
    if(n < 45) mx = (1LL << (n - 1));
    if(k > mx) {
        cout << -1 << endl;
        return;
    }

    --k;
    ll idx = min(n - 1, 45ll); ll curr = n - idx;
    ll l = curr - 1, r = n - 1;
    while(idx > 0) {
        idx--;
        ll b = (k >> idx) & 1;
        if(b) {perm[r] = curr; r--;}
        else {perm[l] = curr; l++;}
        curr++;
    }
    perm[l] = curr;

    for(auto p : perm) cout << p << " ";
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