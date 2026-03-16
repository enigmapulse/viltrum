#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k, p, m; cin >> n >> k >> p >> m;
    vector<ll> a(n); inarr(a, n);

    vector<ll> rep; multiset<ll> s;
    for (ll i = 0; i < k; i++) {
        s.insert(a[i]);
    }
    ll ans = 0;

    if(k == n) {
        cout << m / a[p - 1] << endl;
        return;
    }

    if(p <= k) {
        if(a[p - 1] <= m) {
            ans++; m -= a[p - 1];
        }
        for (ll i = p; i < n; i++) {
            swap(a[i], a[i - 1]);
        }
        p = n; 
        s.clear();
        for (ll i = 0; i < k; i++) {
            s.insert(a[i]);
        }
    }

    
    rep.push_back(*s.begin());
    s.erase(s.begin());
    for (ll i = k; i < n; i++) {
        if(i == p - 1) {
            rep.push_back(a[i]);
            continue;
        }
        s.insert(a[i]);
        rep.push_back(*s.begin());
        s.erase(s.begin());
    }
    
    ll init = 0, tot = accumulate(all(rep), 0LL);
    for (ll i = 0; i < p - k + 1; i++) {
        init += rep[i];
    }
    
    if(init <= m) {
        ans ++; m -= init;
    }

    ans += m / tot;
    cout << ans<< endl;

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