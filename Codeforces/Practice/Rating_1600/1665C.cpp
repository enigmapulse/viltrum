#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 2; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; 
    vector<ll> a(n + 1); a[1] = 1; inarr(a, n);

    vector<ll> child(n + 1, 0);
    for (ll i = 2; i <= n; i++) child[a[i]]++; 
    
    ll cnt = 0;
    for (ll i = 1; i <= n; i++) {
        if(child[i] > 0) {
            cnt++; child[i]--;
        }
    }
    cnt++;
    sort(child.begin() + 1, child.end(), greater()); ll bal = cnt - 1;
    for (ll i = 1; i <= n; i++) {
        if(child[i] > 0) {
            ll diff = max(0ll, min(child[i], bal));
            child[i] -= diff;
            bal--;
        }
    }

    auto chk = [&] (ll x) {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            if(child[i] - x > 0) cnt += (child[i] - x);
        }
        return (cnt <= x);
    };

    ll lo = 0, hi = *max_element(all(child));
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << cnt + lo << endl;
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