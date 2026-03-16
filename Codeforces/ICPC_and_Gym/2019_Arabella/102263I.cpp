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
    vector<ll> a(n); inarr(a, n); sort(all(a));

    vector<ll> pre(n + 1, 0); 
    for (ll i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    } 

    vector<ll> suff(n + 1, 0); 
    for (ll i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    } 

    ll l = 0, r = n - 1, turn = 0, ans = a[r] - a[l];
    cout << ans << " ";
    for (ll k = 3; k <= n; k++) {
        ll nw = 0;
        if(turn == 0) nw = ++l;
        else nw = --r;

        ans += (l + turn) * a[nw] - pre[l + turn];
        ans += suff[r + turn] - (n - r - turn) * a[nw];
        cout << ans << " ";
        turn = turn ^ 1;
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