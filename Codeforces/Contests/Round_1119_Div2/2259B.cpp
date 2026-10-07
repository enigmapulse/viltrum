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
    sort(all(a));

    ll cnt1 = 0, cnt0 = 0, cnt2 = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] & 1) cnt1++;
        else {
            if(a[i] % 4 == 0) cnt2++;
            else cnt0++;
        }
    }
    cout << max({cnt0, cnt1, cnt2}) << endl;
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