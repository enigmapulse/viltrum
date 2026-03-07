#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll l, w, r, g, b; cin >> l >> w >> r >> g >> b;
    
    if(l <= w) swap(l, w);
    auto chk = [&] (ll x, ll y, ll z) {
        if(x < w) return 10LL;
        else x-= w; 
        ll ans = 3;
        vector<ll> perm = {x, y, z}; sort(all(perm));
        do{
            ll curr = 0;
            if(!(perm[0] == l || perm[0] == l + w)) curr++;
            if(!(perm[1] == l || perm[1] == l + w)) curr++;
            ans = min(ans, curr);
        } while(next_permutation(all(perm)));
        
        return ans + 4LL;
    };

    ll mn = 10;
    vector<ll> perm = {r, g, b}; sort(all(perm));
    do{
        mn = min(mn, chk(perm[0], perm[1], perm[2]));
    } while(next_permutation(all(perm)));

    cout << mn << endl;
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