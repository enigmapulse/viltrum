#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } return os << "}";
}
template<typename... Args> void dbg_out(Args&&... args) { ((cerr << " " << args), ...) << endl; }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

bool multipleTests = true;

void solve() {
    ll n, m, v; cin >> n >> m >> v;
    vector<ll> taste(n); inarr(taste, n);

    vector<ll> pre(n, 0), suff(n, 0), prefsm(n, 0);

    for (ll i = 0; i < n; i++) {
        if(i == 0) prefsm[i] = taste[i];
        else prefsm[i] = prefsm[i - 1] + taste[i];
    }
    
    ll curr1 = 0, cnt1 = 0;
    for (ll i = 0; i < n; i++) {
        curr1 += taste[i];
        if(curr1 >= v) {
            ++cnt1; curr1 = 0;
        }
        pre[i] = cnt1;
    }
    
    ll curr2 = 0, cnt2 = 0;
    for (ll i = n - 1; i >= 0; i--) {
        curr2 += taste[i];
        if(curr2 >= v) {
            ++cnt2; curr2 = 0;
        }
        suff[i] = cnt2;
    }

    reverse(all(suff)); auto ut = suff.end(); --ut;
    ll ans = -1;
    if(m == 0) ans = prefsm[n - 1];

    auto it = lower_bound(all(suff), m);
    if(it != suff.end()) {
        ll idx = ut - it; 
        if(idx) ans = max(ans, prefsm[idx - 1]);
    }

    for (ll i = 0; i < n; i++) {
        ll need = m - pre[i];
        if (need <= 0) {
            ll val = prefsm[n - 1] - prefsm[i];
            ans = max(ans, val);
            continue; 
        }
        auto it = lower_bound(all(suff), need);
        if(it != suff.end()) {
            ll idx = ut - it; 
            if (idx > i) {
                ll val = prefsm[idx - 1] - prefsm[i];
                ans = max(ans, val);
            }
        }
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