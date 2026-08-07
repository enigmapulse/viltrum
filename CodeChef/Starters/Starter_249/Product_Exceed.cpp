#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, p; cin >> n >> m >> p;
    ll cnt = 0;
    if(n < m) swap(n, m);
    while(m != n && m * n < p) {
        m++; cnt++;
    }
    while(m * n < p) {
        if(m == n) {n++; cnt++;}
        else {m++; cnt++;}
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