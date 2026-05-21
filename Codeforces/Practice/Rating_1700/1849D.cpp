#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> nxt_zero(n);
    ll curr = n;
    for (ll i = n - 1; i >= 0; i--) {
        if(a[i] == 0) curr = i;
        nxt_zero[i] = curr;
    }
    nxt_zero.push_back(n);
    
    ll idx = 0, cnt = 0;
    while(idx < n) {
        ll nxt = nxt_zero[idx + 1];
        if(nxt == idx + 1 && a[idx] == 0) idx++;
        else {
            ll mx = 0;
            for (ll i = idx; i < nxt; i++) {
                mx = max(mx, a[i]);
            }
            if(mx == 1) {
                if(a[idx] == 0) idx = nxt;
                else idx = nxt + 1;
                
            }
            else idx = nxt + 1;
        }
        cnt++;
    }

    cout << cnt << endl;
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