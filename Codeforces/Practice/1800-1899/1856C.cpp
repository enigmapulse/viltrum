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
    vector<ll> a(n); inarr(a, n);

    // so according to the hints we gotta binary search on the answer
    // so we need a checker function to somehowfind out if max >= mx
    // in at max k ops. 
    
    auto chk = [&] (ll x) {
        // is it possible to get some element greater than equal to x in less than equal to k ops
        for (ll i = 0; i < n; i++) {
            if(a[i] >= x) return true;
        }
        
    };
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