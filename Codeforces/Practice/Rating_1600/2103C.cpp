#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e12;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    for (ll i = 0; i < n; i++) {
        if(a[i] <= k) a[i] = 1;
        else a[i] = -1;
    }
    
    vector<ll> pre(n), suff(n);
    pre[0] = a[0]; suff[n - 1] = a[n - 1];
    for (ll i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
        suff[n - i - 1] = suff[n - i] + a[n - i - 1];
    }
    
    // check 1 first two subarray 
    ll minpos = INF;
    for (ll i = 0; i < n - 1; i++) { // iterating over the end of the second array
        if(minpos != INF && pre[i] - minpos >= 0) {
            cout << "YES" << endl;
            return;
        }
        if(pre[i] >= 0) minpos = min(minpos, pre[i]); // update min positive
    }
    
    // check 2 last two subarray
    minpos = INF;
    for (ll i = n - 1; i > 0; i--) { // iterating over the start of the second array
        if(minpos != INF && suff[i] - minpos >= 0) {
            cout << "YES" << endl;
            return;
        }
        if(suff[i] >= 0) minpos = min(minpos, suff[i]); // update min positive
    }
    
    // check 3 first and last subarrays
    ll r1 = -1; ll l3 = -1;
    for (ll i = 0; i < n - 1; i++) {
        if(r1 == -1 && pre[i] >= 0) r1 = i;
        if(l3 == -1 && suff[n - 1 - i] >= 0) l3 = n - 1 - i;
    }
    if(l3 != -1 && r1 != -1 && l3 - r1 > 1) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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