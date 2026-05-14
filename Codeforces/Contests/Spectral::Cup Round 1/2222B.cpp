#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n); inarr(a, n);

    vector<ll> odd, even;
    for (ll i = 0; i < n; i++) {
        if(i & 1) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    sort(all(odd)); sort(all(even));

    ll sm = accumulate(all(a), 0LL);
    bool chk1 = false, chk2 = false;
    while(q--) {
        ll x; cin >> x;
        if(!(x & 1)) {
            if(!even.empty() && (chk1 == false || even.back() > 0)) {
                sm -= even.back();
                even.pop_back();
                chk1 = true;
            }
        }
        else {
            if(!odd.empty() && (chk2 == false || odd.back() > 0)) {
                sm -= odd.back();
                odd.pop_back();
                chk2 = true;
            }
        }
    }
    
    cout << sm << endl;
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