#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll s, k, m; cin >> s >> k >> m;
    ll rem = m % k;
    if(k >= s) {
        cout << max(0LL, s - rem) << endl;
    }
    else {
        if ((m / k) % 2 == 0) cout << s - rem << endl; 
        else  cout << k - rem << endl; 
        
    }
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