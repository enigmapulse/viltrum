#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n); inarr(a, n);
    vector<ll> ops(m); inarr(ops, m);
    sort(all(ops), greater());
    ops.erase(unique(all(ops)), ops.end());

    vector<ll> pre(n, 0);
    for (ll i = 0; i < n; i++) {
        pre[i] = a[i];
        if(i) pre[i] += pre[i - 1];
    }
    
    ll ans = pre[n - 1] - pre[ops[0] - 1];

    for (ll i = 0; i < ops.size() - 1; i++) {
        ll r = ops[i] - 1, l = ops[i + 1] - 1;
        ll curr = 0;
        curr = pre[r] - pre[l];
        ans += abs(curr);
    }
    ans += abs(pre[ops[ops.size() - 1] - 1]);
    cout << ans << endl;
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