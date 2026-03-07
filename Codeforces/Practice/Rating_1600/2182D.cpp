#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

using namespace std;

bool multipleTests = true;

void solve() {
    // let S be the sum of all a_i
    // then there will be exactly S turns in the entire process
    // since the process contnues cyclically from 1 to n
    // each i will get a turn --> calculable
    // it doesn't make sense to use something from a[0]
    // unless your personal slot is finished
    // so say for a chosen i it is coming x times
    // so I have a choice to put those x in it's slot or 
    // x-1 in its slot 1 in a[0] and so on and so forth
    // total x+1 choices but here I am working backwards
    // like I am building possible a from a given p
    // but I need it opposite for a fixed a all possible p
    // so I already know how many times each p[i] would be coming
    // let's call it f[p[i]] so I want sigma f[p[i]] - a[p[i]] across all to be equal to
    // a[0]

    ll n; cin >> n;
    vector<ll> a(n + 1); inarr(a, n + 1);
    ll S = accumulate(all(a), 0LL); // number of turns

    vector<ll> f(n);
    for (ll i = 1; i <= n; i++) {
        f[i - 1] = (S/n) + (S % n >= i);
    }
    reverse(all(f));
    
    // now I need to distribute all the elements of a[1] to a[n]
    // such that none of them go into a negative one
    ll ans = 1; sort(a.begin() + 1, a.end(), greater());
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        ll target = a[i];
        auto it = lower_bound(all(f), target);
        ll idx = f.end() - it; idx -= cnt;
        if(idx <= 0) {
            cout << 0 << endl;
            return;
        }
        ans = (ans * idx) % MOD;
        ++cnt;
    }
    
    cout << ans << endl;
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