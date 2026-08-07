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
    vector<ll> a(n); inarr(a, n);

    vector<ll> pre(n, 0);
    for (ll i = 0; i < n; i++) {
        pre[i] = a[i];
        if(i) pre[i] += pre[i - 1];
    }

    vector<ll> suff(n, 0);
    for (ll i = n - 1; i >= 0; i--) {
        suff[i] = a[i];
        if(i != n - 1) suff[i] += suff[i + 1];
    }

    vector<ll> mnSuff = pre;
    for (ll i = n - 2; i >= 0; i--) {
        mnSuff[i] = min(mnSuff[i], mnSuff[i + 1]);
    }

    vector<ll> mnPre = pre;
    for (ll i = 1; i < n; i++) {
        mnPre[i] = min(mnPre[i], mnPre[i - 1]);
    }
    
    ll cnt = 0;
    // check if the ith index is a correct starting point
    for (ll i = 0; i < n; i++) {
        // the later part check
        ll atleast = (i ? pre[i - 1] : 0ll);
        if(mnSuff[i] < atleast) continue;

        if(i == 0) {
            cnt++;
            continue;
        }

        atleast = (pre[n - 1] - (i ? pre[i - 1] : 0ll));
        if(mnPre[i - 1] + atleast >= 0) cnt++;
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