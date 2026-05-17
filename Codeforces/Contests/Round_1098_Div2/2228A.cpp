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

    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i] == 0) cnt0++;
        else if(a[i] == 1) cnt1++;
        else cnt2++;
    }
    
    ll ops = cnt0;
    ops += min(cnt1, cnt2);
    ops += (max(cnt1, cnt2) - min(cnt1, cnt2))/3;
    cout << ops << endl;
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