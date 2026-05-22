#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    set<ll> s;
    for (ll i = 1; i <= 2*n; i++) {
        s.insert(i);
    }

    s.erase(1); cout << 1 << " "; ll prev = 1;
    for (ll i = 0; i < n - 1; i++) {
        auto it = *s.begin();
        cout << it << " ";
        s.erase(s.begin());
        auto ut = s.find(prev + it);
        if(ut != s.end()) s.erase(ut);
        prev = it;
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