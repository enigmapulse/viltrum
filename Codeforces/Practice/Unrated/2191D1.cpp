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
    string s; cin >> s;

    vector<ll> suff(n, 0);
    for (ll i = n - 1; i >= 0; i--) {
        if(s[i] == ')') suff[i] = 1;
        if (i != n - 1) suff[i] += suff[i + 1];
    }
    
    ll curr = 0; ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        // let i be the first differing bit 
        if(s[i] == '(') {curr++; continue;}
        else {
            if(suff[i + 1] > curr) ans = max(ans, i + curr + 2);
            curr--;
        }
    }
    
    if(ans == 0) cout << -1 << endl;
    else cout << n - 2 << endl;
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