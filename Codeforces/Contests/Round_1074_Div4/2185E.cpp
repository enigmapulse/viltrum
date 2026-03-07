#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define INF 1e15

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> r(n); inarr(r, n);
    vector<ll> s(m); inarr(s, m);

    sort(all(s)); 

    vector<ll> L(k + 1, 0), R(k + 1, 0);
    string st; cin >> st;
    ll curr = 0, mxl = 0, mxr = 0;
    for(int i = 0; i < k; i++) {
        if(st[i] == 'L') curr--; else curr++;
        
        if(curr < 0) mxl = max(mxl, -curr);
        else mxr = max(mxr, curr);
        L[i+1] = mxl; R[i+1] = mxr;
    }

    vector<int> d(k + 1, 0);
    for (ll i = 0; i < n; i++) {
        ll val = r[i];
        ll l = INF, r = INF;
        auto it = lower_bound(all(s), val);
        if(it != s.end()) r = *it - val;
        if(it != s.begin()) l = val - *prev(it);
        int tl = lower_bound(all(L), l) - L.begin();
        int tr = lower_bound(all(R), r) - R.begin();
        int t = min(tl, tr);
        if(t <= k) d[t]++;
    }
    
    ll cnt = 0;
    for(int i = 1; i <= k; i++) {
        cnt += d[i];
        cout << n - cnt << " ";
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