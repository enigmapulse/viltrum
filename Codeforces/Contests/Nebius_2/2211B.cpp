#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll x, y; cin >> x >> y;
    vector<ll> ans;
    ll s = abs(x - y); ll cnt = 0;
    if(s != 0) {
    for (ll i = 1; i*i <= s; i++) {
        if(s % i == 0){ cnt++;
        if(i * i != s) cnt++;}
    }
}
else cnt = 1;
    for (ll i = 0; i < x; i++) {
        ans.push_back(1);
    }
    for (ll j = 0; j < y; j++)
    {
        ans.push_back(-1);
    }
    
    if(x > y) sort(all(ans), greater());
    else sort(all(ans));

    cout << cnt << endl;
    for(auto z : ans) cout << z << " ";
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