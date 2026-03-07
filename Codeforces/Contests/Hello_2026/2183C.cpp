#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        a[i] = abs(i - k);
    }
    sort(all(a));
    ll curr = 0, cnt = 0;
    for (ll i = 1; i < a.size(); i++) {
        if(curr + a[i] > m) break;
        else {
            curr += a[i];
            cnt++;
        }
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